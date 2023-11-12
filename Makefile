CC := cc
CFLAGS :=

all: mycfetch

mycfetch: main.c config.h
	$(CC) main.c -o mycfetch $(CFLAGS)

install: mycfetch
	cp mycfetch /usr/bin/mycfetch

clean:
	rm mycfetch

.PHONY: all install clean
