# include <stdio.h>
# include <stdlib.h>

void print_help();
void scan_content(char ch, unsigned int* len_line, unsigned int* len_find, char line[], char find[]);
char find_word(unsigned int len_line, unsigned int len_find, char line[], char find[]);

int main(int argc, char* argv[]) {
	char ch;
	FILE* f = stdin;
	char* find = NULL;
	if (argc > 1) {
		find = argv[1];
	} else 
		print_help();

	unsigned int len_find = 0;
	while (find[len_find] != '\0') {
		len_find++;
	}

	unsigned int len_line = 0;
	int buff = 100;
	char line[buff];

	while ((ch = fgetc(f)) != EOF) {
		scan_content(ch, &len_line, &len_find, line, find);

//		if ( len_line + 1 = sizeof(line)/sizeof(line[0]) ) {
//			buff += 100;

	}
	if (len_line > 0) 
		scan_content(ch, &len_line, &len_find, line, find);

	return 0;
}

void scan_content(char ch, unsigned int* len_line, unsigned int* len_find, char line[], char find[]) {
	if (ch == '\n') {
		if (*len_line >= *len_find) {
			char isFound = find_word(*len_line, *len_find, line, find);
			if (isFound == 1) {
				line[*len_line] = '\0';
				printf("%s\n", line);
			}
		}
		*len_line = 0;
	} else {
		line[*len_line] = ch;
		(*len_line)++;
	}
}


char find_word(unsigned int len_line, unsigned int len_find, char line[], char find[]) {
	char isFound = 0;
	for (unsigned int i = 0; i < len_line; i++) {
		if (line[i] == find[0]) {
			for (unsigned int j = 0; j < len_find; j++) {
				if (line[i+j] != find[j]) {
					break;
				} else if (j == len_find-1){
					isFound = 1;
				}
			}
			if (isFound == 1)
				break;
		}
	}

	return isFound;
}

void print_help() {
	printf("./grep <find_word> \n");
	exit(1);
}
