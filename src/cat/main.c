#include <stdio.h>

int readFile(char* file);

int main() {
	readFile("Makefile");
	return 0;
}

int readFile(char* file_name) {
	FILE *f = fopen(file_name, "r");
	if (!f) {
		printf("cat: %s: cannot open\n", file_name);
		return -1;
	}
	printf("SUCCESS");
	return 1;
}
	
