#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <stdarg.h>
#include <inttypes.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <errno.h>
#include <fenv.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <stdarg.h>
#include <inttypes.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <errno.h>
#include <fenv.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

// I/O
typedef struct {
	char *s;
	int len;
	int pos;
} Reader;

typedef struct {
	char *s;
	int len;
	int pos;
} Writer;

Reader newReader(char *s) {
	Reader r;
	r.s = s;
	r.pos = 0;
	r.len = strlen(s);
	return r;
}

Writer newWriter() {
	Writer w;
	w.s = malloc(1024 * 1024);
	w.pos = 0;
	w.len = 1024 * 1024;
	return w;
}

void freeWriter(Writer *w) {
	free(w->s);
}

void writeChar(Writer *w, char c) {
	if (w->pos == w->len) {
		w->len *= 2;
		w->s = realloc(w->s, w->len);
	}
	w->s[w->pos] = c;
	w->pos++;
}

void writeStr(Writer *w, char *s) {
	int l = strlen(s);
	if (w->pos + l >= w->len) {
		w->len = w->pos + l + 1;
		w->s = realloc(w->s, w->len);
	}
	strcpy(w->s + w->pos, s);
	w->pos += l;
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
	writeChar(w, r);
}

void writeInt(Writer *w, int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	writeStr(w, buf);
}

void writeFloat(Writer *w, double d) {
	char buf[100];
	sprintf(buf, "%f", d);
	writeStr(w, buf);
}

void writeRuneSlice(Writer *w, RuneSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeChar(w, s.data[i]);
	}
}

void writeIntSlice(Writer *w, IntSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeInt(w, s.data[i]);
	}
}

void writeFloatSlice(Writer *w, FloatSlice s) {
	for (int i = 0; i < s.len; i++) {
		writeFloat(w, s.data[i]);
	}
}

void writeRune(Writer *w, Rune r) {
