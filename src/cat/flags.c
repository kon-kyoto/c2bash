#include "cat.h"
#include <string.h>
#include <stdlib.h>

FILE* parse_flags(int argc, char* argv[], char* flags, FILE* f) {
    if (argc < 2 || (argc >= 2 && strcmp(argv[1], "--help") == 0)) {
        print_help();
    }
    
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            // Обработка длинных и коротких флагов
            if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--number-nonblank") == 0) {
                *flags |= FLAG_NUMBER_NONBLANK;
            }
            else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "-E") == 0) {
                *flags |= FLAG_END_POINT;
            }
            else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--number") == 0) {
                *flags |= FLAG_NUMBER;
            }
            else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--squeeze-blank") == 0) {
                *flags |= FLAG_SQUEEZE_BLANK;
            }
            else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "-T") == 0) {
                *flags |= FLAG_TAB_POINT;
            }
            else {
                print_help();
            }
        }
        else if (!f) {
            f = read_file(argv[i]);
        }
        else {
            print_help();
        }
    }
    
    // Если файл не указан, читаем из stdin
    if (!f) {
        f = stdin;
    }
    
    return f;
}

void print_help(void) {
    printf("\n./cat [OPTIONS] [FILE]\n\n");
    printf("\t-b --number-nonblank\tнумерует только непустые строки\n");
    printf("\t-e -E\tпоказывает $ в конце строк\n");
    printf("\t-n --number\tнумерует все строки\n");
    printf("\t-s --squeeze-blank\tсжимает несколько пустых строк в одну\n");
    printf("\t-t -T\tпоказывает табуляции как ^I\n\n");
    exit(1);
}
