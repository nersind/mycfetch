CC := gcc
CFLAGS :=

mycfetch: main.c info.c order.c
	$(CC) main.c info.c -o mycfetch $(CFLAGS)

install: mycfetch
	cp mycfetch /usr/bin/mycfetch

clean:
	rm mycfetch
