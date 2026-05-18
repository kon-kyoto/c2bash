# include <stdio.h>
# include <stdlib.h>

void print_help();
// void find_word(char* find, int len_ford, char* line, int len_line);

int main(int argc, char* argv[]) {
	char ch;
	FILE* f = stdin;
	char* find;
	if (argc > 1) {
		find = argv[1];
	} else 
		print_help();

	unsigned int count = 0;
	while (find[count] != '\0') {
		count++;
	}

	unsigned int len_line = 0;
	int buff = 100;
	char line[buff];

	while ((ch = fgetc(f)) != EOF) {
		if (ch == '\n' && len_line >= count) {
			char isFound = 0;
			for (unsigned int i = 0; i < len_line; i++) {
				if (line[i] == find[0]) {
					for (unsigned int j = 0; j < count; j++) {
						if (line[i+j] != find[j]) {
							break;
						} else if (j == count-1){
							printf("%s\n", line);
							isFound = 1;
						}
					}
					if (isFound == 1)
						break;
				}
			}
			len_line = 0;
		} else if (ch == '\n') {
			len_line = 0;
		} else {
			line[len_line] = ch;
			len_line++;
		}


//		if ( len_line + 1 = sizeof(line)/sizeof(line[0]) ) {
//			buff += 100;

	}

	return 0;
}

void print_help() {
	printf("./grep <find_word> \n");
	exit(1);
}
