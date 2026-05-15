#include "cat.h"
#include <stdio.h>

FILE* read_file(const char* file_name) {
    FILE* f = fopen(file_name, "r");
    
    if (!f) {
        fprintf(stderr, "cat: %s: cannot open file\n", file_name);
        return NULL;
    }
    
    return f;
}
