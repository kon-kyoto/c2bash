CC = gcc
SH = shc
CFLAGS =  -Wall -Werror -Wextra -std=c99
SOURCES_CAT = src/cat.c src/cat/flags.c src/cat/content.c src/cat/file.c
SOURCES_GCCIDE = src/gccide/main.sh
SOURCES_GREP = src/grep/main.c

.PHONY: build rebuild cat clean

build: cat gccide grep

rebuild: clean build

cat: 
	$(CC) $(CFLAGS) $(SOURCES_CAT) -o cat

gccide: 
	$(SH) -f $(SOURCES_GCCIDE) -o gccide

grep:
	$(CC) $(CFLAGS) $(SOURCES_GREP) -o grep

clean:
	rm -f cat gccide
