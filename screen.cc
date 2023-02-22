#include <aed.h>
#include <version.h>
#include <terminal/size.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

void statusLine() {
	unsigned int w, h;
	term::get_size(w, h);
	
	// get cursor at the bottom of the screen
	write(STDOUT_FILENO, "\x1b[999C", 7);
	write(STDOUT_FILENO, "\x1b[999B", 7);

	// write the status line with white background and black text
	// we want the status line to look like this:
	// "<N> filename.txt 					   AED v0.1.0 | <cursor position>"
	// where <N> is the mode (insert or normal), <cursor position> is the current cursor position
	char filename[] = "filename.txt";
	char status[80], rstatus[80];
	// FIXME: the first letter of the file name is on the previous row that is before the status line
	int len = snprintf(status, sizeof(status), "%s - %s", filename, AED_VERSION);
	int rlen = snprintf(rstatus, sizeof(rstatus), "%d/%d", 1, 1);
	if (len > w) len = w;
	write(STDOUT_FILENO, "\x1b[7m", 4);
	write(STDOUT_FILENO, status, len);
	while (len < w) {
		if (w - len == rlen) {
			write(STDOUT_FILENO, rstatus, rlen);
			break;
		} else {
			write(STDOUT_FILENO, " ", 1);
			len++;
		}
	}
	write(STDOUT_FILENO, "\x1b[m", 3);
	

	// reset the colors
	write(STDOUT_FILENO, "\x1b[0m", 4);

	// move the cursor back to the top left corner
	write(STDOUT_FILENO, "\x1b[H", 3);
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

	printTildeRows();
	write(STDOUT_FILENO, "\x1b[H", 3);
	
	statusLine();
}
