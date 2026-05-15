#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* readFile(char* file);
FILE* arg2flags(int argc, char* argv[], char flags[], FILE* f);
void returnContent(FILE* f, char flags[5]);
void exitWithHelp();

int main(int argc, char* argv[]) {
	// 5 flags [ number-nonblanck, end-point, number, squeeze-blank, tab-point ]
	char flags[5] = {0};
	FILE* f = NULL;
	
	f = arg2flags(argc, argv, flags, f);

	if(f) {
		returnContent(f, flags);
	}
	return 0;
}

void returnContent(FILE* f, char flags[5]) {
	char count_line = 1;      // counter of line
	char count_nonline = 1;   // counter of line withot content

	int ch;
	
	while ( (ch = fgetc(f)) != EOF ) {
		if (flags[3] && count_nonline > 1 && ch == '\n')
			continue;
		
		if (count_nonline >= 1 && (flags[2] || (flags[0] && ch != '\n'))) {
			printf("%d ", count_line++);
		}

		if ( ch == '\n' ) {
			if (flags[1]) 
				printf("$");
			count_nonline++;
		} else
			count_nonline = 0;

		printf("%c", ch);
	}
}

FILE* arg2flags(int argc, char* argv[], char flags[], FILE* f) {
	if ( argc < 2 || (argc >= 2 && strcmp(argv[1], "--help")  == 0) ) {
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

	return f;
}

FILE* readFile(char* file_name) {
	FILE *f = fopen(file_name, "r");
	if (!f) {
		printf("cat: %s: cannot open\n", file_name);
		return NULL;
	}
	
	return f;
}
	

void exitWithHelp() {
	printf("\n./cat [OPTIONS] [FILE]\n\n");
	printf("\t-b --number-nonblanck\tnumbers only non-empty lines\n");
	printf("\t-e -E\tdisplays $ at line ends\n");
	printf("\t-n --number number all output lines\n");
	printf("\t-s --squeeze-blank\tsqueeze multiple adjacent blank lines\n");
	printf("\t-t -T\tbut also display tabs as ^I\n\n");
	exit(1);
}
