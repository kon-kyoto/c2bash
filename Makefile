CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99
SOURCES_CAT = src/cat.c src/cat/flags.c src/cat/content.c src/cat/file.c
SOURCES_GCCIDE = src/gccide/main.sh

.PHONY: build rebuild cat clean

build: cat gccide

rebuild: clean build

cat: $(OBJECTS_CAT) 
	$(CC) $(CFLAGS) $(SOURCES_CAT) -o cat

gccide: 
	shc -f $(SOURCES_GCCIDE) -o gccide

clean:
	rm -f cat gccide
