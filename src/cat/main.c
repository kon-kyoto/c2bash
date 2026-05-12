#include <stdio.h>

FILE* readFile(char* file);

int main(int argc, char *argv[]) {
	// 5 flags [ number-nonblanck, end-point, number, squeeze-blank, tab-point ]
	int flags[5] = [0, 0 ,0 ,0 ,0];
	FILE *f = readFile("Makefile");
	return 0;
}

FILE* readFile(char* file_name) {
	FILE *f = fopen(file_name, "r");
	if (!f) {
		printf("cat: %s: cannot open\n", file_name);
		return NULL;
	}
	
	return f;
}
	
