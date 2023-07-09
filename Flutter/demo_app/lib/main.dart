import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({Key? key, required this.title}) : super(key: key);

  final String title;

  @override
  // ignore: library_private_types_in_public_api
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        padding: const EdgeInsets.all(25),
        decoration: const BoxDecoration(
          color: Color.fromARGB(255, 31, 31, 31),
        ),
        child: Column(
          children: <Widget>[
            CustomContainerOne(
              heading: 'Upcoming',
              body: EventCard(
                title: "Random Event",
                info: "Lorem ipsum ",
                eventTime: DateTime.now(),
              ),
            ),
          ],
        ),
      ),
    );
  }
}

// ignore: must_be_immutable
class CustomContainerOne extends StatelessWidget {
  final String heading;

  Widget body;

  CustomContainerOne({Key? key, required this.heading, required this.body})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      decoration: const BoxDecoration(),
      child: Column(children: [
        Row(children: [
          Text(
            heading,
            style: const TextStyle(
                color: Colors.white, fontSize: 25, fontWeight: FontWeight.bold),
          ),
        ]),
        const Padding(padding: EdgeInsets.all(4)),
        Row(children: [
          Expanded(
            child: Container(
              height: 1.0,
              color: Colors.grey,
            ),
          ),
        ]),
        const Padding(padding: EdgeInsets.all(4)),
        Container(
          child: body,
        ),
      ]),
    );
  }
}

// ignore: must_be_immutable
class EventCard extends StatelessWidget {
  final String title;

  final String info;

  final DateTime eventTime;

  final Color tagColour;

  const EventCard(
      {Key? key,
      required this.title,
      required this.info,
      required this.eventTime,
      this.tagColour = Colors.purple})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      width: double.maxFinite,
      height: 45.0,
      decoration: BoxDecoration(
          color: const Color.fromARGB(255, 17, 17, 17),
          borderRadius: BorderRadius.circular(8)),
      padding: const EdgeInsets.symmetric(horizontal: 10.0, vertical: 10.0),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.start,
        children: [
          Container(
            decoration: BoxDecoration(
              border: Border.all(width: 2.0, color: tagColour),
              borderRadius: BorderRadius.circular(12),
            ),
            width: 4.0,
            height: double.maxFinite,
            margin: const EdgeInsets.only(right: 15.0),
          ),
          Column(mainAxisAlignment: MainAxisAlignment.center, children: [
            Text(title, style: const TextStyle(color: Colors.white)),
            //Text(info, style: const TextStyle(color: Colors.white)),
          ]),
          Expanded(
            child: Row(mainAxisAlignment: MainAxisAlignment.end, children: [
              Text(
                  "In ${DateTime.now().difference(eventTime).inMinutes} minute(s)",
                  style: const TextStyle(color: Colors.grey))
            ]),
          ),
        ],
      ),
    );
  }
}
