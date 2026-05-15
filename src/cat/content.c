#include "cat.h"

void print_content(FILE* f, const char* flags) {
    int line_counter = 1;      // counter line
    int blank_counter = 1;     // counter blankline
    
    int ch;
    
    while ((ch = fgetc(f)) != EOF) {
        // FLag -s
        if ((*flags & FLAG_SQUEEZE_BLANK) && blank_counter > 1 && ch == '\n') {
            continue;
        }
        
        // Flag -b и -n
        if (blank_counter >= 1 && 
            ((*flags & FLAG_NUMBER) || ((*flags & FLAG_NUMBER_NONBLANK) && ch != '\n'))) {
            printf("%d ", line_counter++);
        }
        
        // Flag -e, -E
        if (ch == '\n') {
            if (*flags & FLAG_END_POINT) {
                printf("$");
            }
            blank_counter++;
        }
        else {
            blank_counter = 0;
        }
        
        // Flag -t, -T
        if ((*flags & FLAG_TAB_POINT) && ch == '\t') {
            printf("^I");
            continue;
        }
        
        putchar(ch);
    }
}
