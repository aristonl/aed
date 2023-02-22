#include <aed.h>
#include <terminal/size.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

void statusLine() {
	unsigned int w, h;
	term::get_size(w, h);
	
}

void printTildeRows() {
	unsigned int w, h;
	term::get_size(w, h);
	
	for (unsigned int i = 0; i < h; i++) {
		write(STDOUT_FILENO, "~\r\n", 3);
	}
}

void refreshScreen() {
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);

	statusLine();
	printTildeRows();
	write(STDOUT_FILENO, "\x1b[H", 3);
}
