CC = gcc
CFLAGS = -Wall -Werror -Wextra

.PHONY: build clean

build: cat

cat: src/cat/main.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f cat
