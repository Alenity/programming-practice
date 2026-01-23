module test_led_sw_1;

logic [4:0] led;
logic [1:0] sw;

led_sw_1 ls0 (.*);

initial
	begin
		#0ns sw[0] = 0;
		#0ns sw[1] = 0;
		#10ns sw[0] = 1;
		#0ns sw[1] = 0;
		#10ns sw[0] = 1;
		#0ns sw[1] = 1;
		#10ns sw[0] = 0;
		#0ns sw[1] = 1;
	end
	
endmodule
