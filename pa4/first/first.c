#include "first.h"
int traverse(int *arr, int inputCounter) {
	int i;
	for (i = inputCounter + 1; i >= 2; i--) {
		arr[i] = !arr[i];
		if (arr[i] == 1) {
			return 1;
		}
	}
	return 0;
}
int getIndex(int size, char **arr, char *var) {
	int i;
	for (i = 0; i < size; i++) {
		if (strcmp(arr[i], var) == 0) {
			return i;
		}
	}
	return -1;
}
int main(int argc, char* argv[]) {
	FILE *file = fopen(argv[1], "r");
	int counter = 0;
	struct myStruct* instruct = NULL;
	int size = 2;
	int inputCounter = 0;
	int outputCounter = 0;
	int startCheck = 1;
	char directions[17];
	char **variables;
	int *data = malloc(size * sizeof(int));

	fscanf(file, " %s", directions);
	fscanf(file, "%d", &inputCounter);

	size += inputCounter;
	variables = malloc(size * sizeof(char *));
	variables[0] = malloc(2 * sizeof(char));
	variables[1] = malloc(2 * sizeof(char));
	
	int i;
	for (i = 0; i < inputCounter; i++) {
		variables[i + 2] = malloc(17 * sizeof(char));
		fscanf(file, "%*[: ]%s", variables[i + 2]);
	}

	fscanf(file, " %s", directions);
	fscanf(file, "%d", &outputCounter);
	size += outputCounter;
	variables = realloc(variables, size * sizeof(char *));
	for (i = 0; i < outputCounter; i++) {
		variables[i + inputCounter + 2] = malloc(17 * sizeof(char));
		fscanf(file, "%*[: ]%s", variables[i + inputCounter + 2]);
	}

	while (!feof(file)) {
		int numInputs = 2, numOutputs = 1;
		struct myStruct logGate; char word[25];
		int check = fscanf(file, " %s", directions);
		if (check != 1) {
			break;
		}
		counter++;
		startCheck++;
		strcpy(logGate.gate, directions);

		logGate.inputs = malloc(numInputs * sizeof(int));
		logGate.outputs = malloc(numOutputs * sizeof(int));

		for (i = 0; i < numInputs; i++) {
			fscanf(file, "%*[: ]%s", word);
			logGate.inputs[i] = getIndex(size, variables, word);
		}
		data = malloc(size * sizeof(int));

		for (i = 0; i < numOutputs; i++) {
			fscanf(file, "%*[: ]%s", word);
			int temp = getIndex(size, variables, word);
			if (temp == -1) {
				size++;
				variables = realloc(variables, size * sizeof(char *));
				variables[size - 1] = malloc(17 * sizeof(char));
				strcpy(variables[size - 1],word);
				logGate.outputs[i] = size - 1;
			}
			else {
				logGate.outputs[i] = temp;
			}
		}

		if (!instruct) {
			instruct = malloc(sizeof(struct myStruct));
		}
		else {
			instruct = realloc(instruct, counter * sizeof(struct myStruct));
		}
		instruct[counter - 1] = logGate;
	}
	int x = 0;
	while (startCheck != 0) {
		for (i = 0; i < inputCounter; i++) {
			printf("%d ", data[i + 2]);
		}
		for (i = 0; i < counter; i++) {
			struct myStruct logGate = instruct[i];
			if (strcmp(logGate.gate, "NOT") == 0) {
				NOT(data, logGate.inputs[0], logGate.outputs[0]);
			for (x = 0; x < size; x++){
	//		printf("%d ", data[x]);
			}
			}
			if (strcmp(logGate.gate, "AND") == 0) {
				AND(data, logGate.inputs[0], logGate.inputs[1], logGate.outputs[0]);
			}
			if (strcmp(logGate.gate, "OR") == 0) {
				OR(data, logGate.inputs[0], logGate.inputs[1], logGate.outputs[0]);
			}
			if (strcmp(logGate.gate, "NAND") == 0) {
				NAND(data, logGate.inputs[0], logGate.inputs[1], logGate.outputs[0]);
			}
			if (strcmp(logGate.gate, "NOR") == 0) {
				NOR(data, logGate.inputs[0], logGate.inputs[1], logGate.outputs[0]);
			}
			if (strcmp(logGate.gate, "XOR") == 0) {
				XOR(data, logGate.inputs[0], logGate.inputs[1], logGate.outputs[0]);
			}
		}
		for (i = 0; i < outputCounter; i++) {
			printf("%d ", data[inputCounter + i + 2]);
		}
		printf("\n");

		if (!traverse(data, inputCounter)) {
			fclose(file);
			break;
		}
	}
	return 0;
}
void NOT(int *data, int input, int outindex) {
	data[outindex] = !data[input];
}

void AND(int *data, int input1, int input2, int outindex) {
	data[outindex] = data[input1] && data[input2];
}

void OR(int *data, int input1, int input2, int outindex) {
	data[outindex] = data[input1] || data[input2];
}

void NAND(int *data, int input1, int input2, int outindex) {
	data[outindex] = !(data[input1] && data[input2]);
}

void NOR(int *data, int input1, int input2, int outindex) {
	data[outindex] = !(data[input1] || data[input2]);
}

void XOR(int *data, int input1, int input2, int outindex) {
	data[outindex] = data[input1] ^ data[input2];
}
