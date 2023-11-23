PREFIX ?= /usr/local

all: mycfetch

install: mycfetch
	install -m 644 mycfetch $(PREFIX)/bin/

clean:
	rm -f mycfetch

.PHONY: all install clean
