#include <terminal/size.h>

#include <sys/ioctl.h>

namespace term {
	bool get_size(unsigned int &w, unsigned int &h) {
		struct winsize ws;
		if (ioctl(0, TIOCGWINSZ, &ws) == -1) {
			return false;
		}
		w = ws.ws_col;
		h = ws.ws_row;
		return true;
	}
}