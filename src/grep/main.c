# include <stdio.h>
# include <stdlib.h>

void print_help();
// void find_word(char* find, int len_ford, char* line, int len_line) {

int main(int argc, char* argv[]) {
	char ch;
	FILE* f = stdin;
	char* find;
	if (argc > 1) {
		find = argv[1];
		printf("find_word: %s\n\n\n", argv[1]);
	} else {
		print_help();
	}

	int count = 0;
	while (find[count] != '\0') {
		count++;
	}

	unsigned int len_line = 0;
	int buff = 100;
	char line[buff];

	while ((ch = fgetc(f)) != EOF) {
		if (ch == '\n') {
			printf("new line");
			buff = 100;
		}
		line[len_line] = ch;
		len_line++;
//		if ( len_line + 1 = sizeof(line)/sizeof(line[0]) ) {
//			buff += 100;

	}
	printf("%c", line[0]);

	return 0;
}

void print_help() {
	printf("./grep <find_word> \n");
	exit(1);
}
