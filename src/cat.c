#include "cat/cat.h"

int main(int argc, char* argv[]) {
	char flags = 0;
	FILE* f = NULL;

	f = parse_flags(argc, argv, &flags, f);

	if (f) {
		print_content(f, &flags);
	}

	return 0;
}
