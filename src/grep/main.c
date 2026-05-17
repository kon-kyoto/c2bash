# include <stdio.h>

int main() {
	char flags = 0, ch;
	FILE* f = stdin;

	while ((ch = fgetc(f)) != EOF) {
		printf("%c", ch);
	}

	return 0;
}
