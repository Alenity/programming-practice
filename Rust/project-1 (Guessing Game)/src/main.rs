use std::io;
use rand::Rng;
use std::cmp::Ordering;

fn main() {
    println!("Which would you like to do?");
    println!("1) Play guessing game");
    println!("2) Convert F to C");
    println!("3) Generate nth term of fibonacci sequence");

    loop {    
        println!("(Please type a number)");
        
        let mut user_choice = String::new();

        io::stdin()
            .read_line(&mut user_choice)
            .expect("Failed to read line");

        let user_choice: u32 = match user_choice.trim().parse() {
            Ok(num) => num,
            Err(_) => continue
        };
    }
}

fn guessing_game() {
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1..=100);

    loop {
        println!("Please input your guess:");

        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");
        
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("You guessed: {guess}");

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("Congratulations!");
                println!("You win!");
                break;
            }
        }
    }
}

fn fahrenheit_to_celsius(x: i32) -> i32{
    (x - 32) * (5/9)
}

fn fibonacci_num_gen(x: u32) -> u32 {
    (x-1) + (x-2)
}