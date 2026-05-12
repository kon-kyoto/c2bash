#include <stdio.h>

FILE* readFile(char* file);
void returnContent(FILE* f, int flags[5]);

int main() {
	// 5 flags [ number-nonblanck, end-point, number, squeeze-blank, tab-point ]
	int flags[5] = {0, 0 ,0 ,0 ,0};
	FILE *f = readFile("Makefile");
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

	char buff[256];
	while ( fgets(buff, sizeof(buff), f) != NULL ) {
		printf("%s", buff);
	}
}
