#include <aed.h>
#include <unistd.h>

void refreshScreen() {
	write(STDOUT_FILENO, "\x1b[2J", 4);
}