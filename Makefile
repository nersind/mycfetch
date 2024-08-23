PREFIX ?= /usr/local
BINDIR ?= ${PREFIX}/bin
MANDIR ?= ${PREFIX}/share/man

all: mycfetch

mycfetch: config.h defs.h

clean:
	rm -f mycfetch

install: mycfetch mycfetch.1
	install -d ${DESTDIR}${BINDIR} ${DESTDIR}${MANDIR}/man1
	install mycfetch ${DESTDIR}${BINDIR}
	install -m 644 mycfetch.1 ${DESTDIR}${MANDIR}/man1

uninstall:
	rm -f ${DESTDIR}${BINDIR}/mycfetch
	rm -f ${DESTDIR}${MANDIR}/man1/mycfetch.1

.PHONY: all install clean
