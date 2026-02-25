module fullAdder (
		input logic a, b, carryIn,
		output logic, su, carryout
	);

logic i, j, k ,l;

xor g0 (i, a, b);
xor g1 (sum, i, carryIn);
and g2 (j, a, b);
and g3 (k, a, carryIn);
and g4 (l, b, carryIn);
or g5 (carryOut, j, k, l);
endmodule