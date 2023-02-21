#define CTRL_KEY(k) ((k) & 0x1f)

void die(const char *s);

void disableRawMode();
void enableRawMode();

char editorReadKey();
void editorProcessKeypress();

void refreshScreen();
