#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* readFile(char* file);
void returnContent(FILE* f, int flags[5]);
void exitWithHelp();

int main(int argc, char* argv[]) {
	// 5 flags [ number-nonblanck, end-point, number, squeeze-blank, tab-point ]
	int flags[5] = {0};
	FILE* f = NULL;
	
	if ( argc < 2 || (argc >= 2 && strcmp(argv[1], "--help") ) == 0) {
		exitWithHelp();
	}

	for ( int i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--number-nonblanck") == 0)
					flags[0] = 1;
			else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "-E") == 0)
					flags[1] = 1;
			else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--number") == 0)
					flags[2] = 1;
			else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--squeeze-blank") == 0)
					flags[3] = 1;
			else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--T") == 0)
					flags[4] = 1;
			else 
				exitWithHelp();
		} else if (!f) {
			f = readFile(argv[i]);
		} else 
			exitWithHelp();
	}

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

void exitWithHelp() {
	printf("./cat [OPTIONS] [FILE]\n");
	exit(1);
}
