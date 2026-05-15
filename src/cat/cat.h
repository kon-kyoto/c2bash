#ifdef CAT_H
#define CAT_H

#include <stdio.h>

#define FLAG_NUMBER_NONBLANK 1
#define FLAG_END_POINT 2
#define FLAG_NUMBER 4
#define FLAG_SQUEEZE_BLANK 8
#define FLAG_TAB_POINT 16

FILE* read_file(const char* file_name);
FILE* parse_flags(int argc, char* argv[], char* flags, FILE* f);
void print_content(FILE* f, const char* flags);
void print_help(void);

#endif
