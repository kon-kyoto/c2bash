#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* readFile(char* file);
FILE* arg2flags(int argc, char* argv[], char* flags, FILE* f);
void returnContent(FILE* f, char* flags);
void exitWithHelp();

int main(int argc, char* argv[]) {
	// 5 flags [ number-nonblank, end-point, number, squeeze-blank, tab-point ]
	char flags[5] = {0};
	FILE* f = NULL;
	
	f = arg2flags(argc, argv, flags, f);

	if(f) {
		returnContent(f, flags);
	}
	return 0;
}

void returnContent(FILE* f, char* flags) {
	char count_line = 1;      // счётчик строк
	char count_nonline = 1;   // счётчик непустых строк

	int ch;
	
	while ( (ch = fgetc(f)) != EOF ) {
		if ((*flags & 8) && count_nonline > 1 && ch == '\n')
			continue;
		
		if (count_nonline >= 1 && ((*flags & 4) || ((*flags & 1) && ch != '\n'))) {
			printf("%d ", count_line++);
		}

		if ( ch == '\n' ) {
			if ((*flags & 2)) 
				printf("$");
			count_nonline++;
		} else
			count_nonline = 0;

		if ((*flags & 16) && ch == '\t') {
			printf("^I");
			continue;
		}

		printf("%c", ch);
	}
}

FILE* arg2flags(int argc, char* argv[], char* flags, FILE* f) {
	if ( argc < 2 || (argc >= 2 && strcmp(argv[1], "--help")  == 0) ) {
		exitWithHelp();
	}

	for ( int i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--number-nonblank") == 0)
					*flags |= 1;   // бит 0: нумерация непустых строк
			else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "-E") == 0)
					*flags |= 2;   // бит 1: показывать $ в конце строк
			else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--number") == 0)
					*flags |= 4;   // бит 2: нумеровать все строки
			else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--squeeze-blank") == 0)
					*flags |= 8;   // бит 3: сжимать пустые строки
			else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "-T") == 0)
					*flags |= 16;  // бит 4: показывать табуляции
			else 
				exitWithHelp();
		} else if (!f) {
			f = readFile(argv[i]);
		} else 
			exitWithHelp();
	}
	
	// Если файл не указан, читаем из stdin
	if (!f) {
		f = stdin;
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
	printf("\t-b --number-nonblank\tнумерует только непустые строки\n");
	printf("\t-e -E\tпоказывает $ в конце строк\n");
	printf("\t-n --number нумерует все строки\n");
	printf("\t-s --squeeze-blank\tсжимает несколько пустых строк в одну\n");
	printf("\t-t -T\tпоказывает табуляции как ^I\n\n");
	exit(1);
}
