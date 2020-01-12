#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct myStruct {
	char gate[17];
	int *inputs;
	int *outputs;
};

void NOT(int *numbers, int input, int output);
void AND(int *numbers, int input1, int input2, int output);	
void OR(int *numbers, int input1, int input2, int output);
void NAND(int *numbers, int input1, int input2, int output);
void NOR(int *numbers, int input1, int input2, int output);
void XOR(int *numbers, int input1, int input2, int output);
