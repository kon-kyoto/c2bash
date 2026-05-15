CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99
SOURCES_CAT = src/cat.c src/cat/flags.c src/cat/content.c src/cat/file.c

.PHONY: build rebuild cat clean

build: cat

rebuild: clean build

cat: $(OBJECTS_CAT) 
	$(CC) $(CFLAGS) $(SOURCES_CAT) -o cat

clean:
	rm -f cat
