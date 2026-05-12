#include <stdio.h>
#include <string.h>

FILE* readFile(char* file);
void returnContent(FILE* f, int flags[5]);

int main(int argc, char* argv[]) {
	// 5 flags [ number-nonblanck, end-point, number, squeeze-blank, tab-point ]
	if ( argc >= 2 && strcmp(argv[1], "--help") == 0) {
		printf("./cat [OPTIONS] [FILE]\n");
		return 0;
	}

	int flags[5] = {0, 0 ,0 ,0 ,0};
	FILE *f = readFile("test.txt");
	if(f) {
		returnContent(f, flags);
	}
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
	
void returnContent(FILE* f, int flags[5]) {
	int count_line = 1;
	int count_nonline = 0;

	int ch;
	while ( (ch = fgetc(f)) != EOF ) {
		printf("%c", ch);
	}
}
