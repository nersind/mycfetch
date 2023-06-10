CC := gcc
CFLAGS :=

mycfetch:
	$(CC) main.c info.c -o mycfetch $(CFLAGS)

install: mycfetch
	cp mycfetch /usr/bin/mycfetch
