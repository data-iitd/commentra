#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#include <locale.h>
#include <wctype.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#include <locale.h>
#include <wctype.h>
#include <wchar.h>

// I/O
typedef struct {
	char *s;
	int len;
	int pos;
} Reader;

typedef struct {
	char *buf;
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

Writer newWriter(int size) {
	Writer w;
	w.buf = malloc(size);
	w.pos = 0;
	w.len = size;
	return w;
}

void freeWriter(Writer w) {
	free(w.buf);
}

int readChar(Reader *r) {
	if (r->pos >= r->len) {
		return -1;
	}
	return r->s[r->pos++];
}

int peekChar(Reader *r) {
	if (r->pos >= r->len) {
		return -1;
	}
	return r->s[r->pos];
}

void skipSpaces(Reader *r) {
	int c;
	do {
		c = readChar(r);
	} while (isspace(c));
	r->pos--;
}

int readInt(Reader *r) {
	int c, neg = 0, res = 0;
	skipSpaces(r);
	c = readChar(r);
	if (c == '-') {
		neg = 1;
		c = readChar(r);
	}
	for (; isdigit(c); c = readChar(r)) {
		res = res*10 + c - '0';
	}
	r->pos--;
	return neg? -res : res;
}

long long readLong(Reader *r) {
	long long c, neg = 0, res = 0;
	skipSpaces(r);
	c = readChar(r);
	if (c == '-') {
		neg = 1;
		c = readChar(r);
	}
	for (; isdigit(c); c = readChar(r)) {
		res = res*10 + c - '0';
	}
	r->pos--;
	return neg? -res : res;
}

double readDouble(Reader *r) {
	double c, neg = 0, res = 0, div = 1;
	skipSpaces(r);
	c = readChar(r);
	if (c == '-') {
		neg = 1;
		c = readChar(r);
	}
	for (; isdigit(c); c = readChar(r)) {
		res = res*10 + c - '0';
	}
	if (c == '.') {
		c = readChar(r);
		for (; isdigit(c); c = readChar(r)) {
			res += (c - '0') / (div *= 10);
		}
	}
	r->pos--;
	return neg? -res : res;
}

char *readString(Reader *r) {
	int c, len = 0;
	skipSpaces(r);
	c = readChar(r);
	if (c!= '"') {
		r->pos--;
		return NULL;
	}
	for (c = readChar(r); c!= '"'; c = readChar(r)) {
		if (c == '\\') {
			readChar(r);
		}
		len++;
	}
	char *res = malloc(len + 1);
	int i = 0;
	for (c = readChar(r); c!= '"'; c = readChar(r)) {
		if (c == '\\') {
			res[i++] = readChar(r);
		} else {
			res[i++] = c;
		}
	}
	res[i] = 0;
	return res;
}

void writeChar(Writer *w, int c) {
	if (w->pos >= w->len) {
		w->len = w->len * 2 + 1;
		w->buf = realloc(w->buf, w->len);
	}
	w->buf[w->pos++] = c;
}

void writeInt(Writer *w, int n) {
	if (n < 0) {
		writeChar(w, '-');
		n = -n;
	}
	if (n == 0) {
		writeChar(w, '0');
		return;
	}
	int size = 1;
	for (int i = n; i > 0; i /= 10) {
		size++;
	}
	for (int i = size - 1; i >= 0; i--) {
		writeChar(w, '0' + n%10);
		n /= 10;
	}
}

void writeLong(Writer *w, long long n) {
	if (n < 0) {
		writeChar(w, '-');
		n = -n;
	}
	if (n == 0) {
		writeChar(w, '0');
		return;
	}
	int size = 1;
	for (long long i = n; i > 0; i /= 10) {
		size++;
	}
	for (int i = size - 1; i >= 0; i--) {
		writeChar(w, '0' + n%10);
		n /= 10;
	}
}

void writeDouble(Writer *w, double n) {
	if (n < 0) {
		writeChar(w, '-');
		n = -n;
	}
	if (n == 0) {
		writeChar(w, '0');
		return;
	}
	int size = 1;
	for (double i = n; i > 0; i /= 10) {
		size++;
	}
	for (int i = size - 1; i >= 0; i--) {
		writeChar(w, '0' + n%10);
		n /= 10;
	}
}

void writeString(Writer *w, char *s) {
	writeChar(w, '"');
	for (int i = 0; s[i]!= 0; i++) {
		if (s[i] == '"') {
			writeChar(w, '\\');
		}
		writeChar(w, s[i]);
	}
	writeChar(w, '"');
}

// Arithmetic
#define max(a, b) ((a) > (b)? (a) : (b))
#define min(a, b) ((a) < (b)? (a) : (b))
#define abs(x) ((x) < 0? -(x) : (x))
#define pow(x, y) ((int)pow((double)(x), (double)(y)))
#define ceil(a, b) ((a) / (b) + ((a) % (b) > 0))

// Sort
typedef struct {
	int len;
	int *arr;
} IntSlice;

IntSlice newIntSlice(int len) {
	IntSlice s;
	s.len = len;
	s.arr = malloc(len * sizeof(int));
	return s;
}

void freeIntSlice(IntSlice s) {
	free(s.arr);
}

int intSliceLen(IntSlice s) {
	return s.len;
}

int intSliceLess(IntSlice s, int i, int j) {
	return s.arr[i] < s.arr[j];
}

void intSliceSwap(IntSlice s, int i, int j) {
	int tmp = s.arr[i];
	s.arr[i] = s.arr[j];
	s.arr[j] = tmp;
}

void intSliceSort(IntSlice s) {
	qsort(s.arr, s.len, sizeof(int), intSliceLess);
}

typedef struct {
	int len;
	int *arr;
} IntSlice;

IntSlice newIntSlice(int len) {
	IntSlice s;
	s.len = len;
	s.arr = malloc(len * sizeof(int));
	return s;
}

void freeIntSlice(IntSlice s) {
	free(s.arr);
}

int intSliceLen(IntSlice s) {
	return s.len;
}

int intSliceLess(IntSlice s, int i, int j) {
	return s.arr[i] < s.arr[j];
}

void intSliceSwap(IntSlice s, int i, int j) {
	int tmp = s.arr[i];
	s.arr[i] = s.arr[j];
	s.arr[j] = tmp;
}

void intSliceSort(IntSlice s) {
	qsort(s.arr, s.len, sizeof(int), intSliceLess);
}

typedef struct {
	int len;
	int *arr;
} IntSlice;

IntSlice newIntSlice(int len) {
	IntSlice s;
	s.len = len;
	s.arr = malloc(len * sizeof(int));
	return s;
}

void freeIntSlice(IntSlice s) {
	free(s.arr);
}

int intSliceLen(IntSlice s) {
	return s.len;
}

int intSliceLess(IntSlice s, int i, int j) {
	return s.arr[i] < s.arr[j];
}

void intSliceSwap(IntSlice s, int i, int j) {
	int tmp = s.arr[i];
	s.arr[i] = s.arr[j];
	s.arr[j] = tmp;
}

void intSliceSort(IntSlice s) {
	qsort(s.arr, s.len, sizeof(int), intSliceLess);
}

typedef struct {
	int len;
	int *arr;
} IntSlice;

IntSlice newIntSlice(int len) {
	IntSlice s;
	s.len = len;
	s.arr = malloc(len * sizeof(int));
	return s;
}

void freeIntSlice(IntSlice s) {
	free(s.arr);
}

int intSliceLen(IntSlice s) {
	return s.len;
}

int intSliceLess(IntSlice s, int i, int j) {
	return s.arr[i] < s.arr[j];
}

void intSliceSwap(IntSlice s, int i, int j) {
	int tmp = s.arr[i];
	s.arr[i] = s.arr[j];
	s.arr[j] = tmp;
}

void intSliceSort(IntSlice s) {
	qsort(s.arr, s.len, sizeof(int), intSliceLess);
}

typedef struct {
	int len;
	int *arr;
} IntSlice;

IntSlice newIntSlice(int len) {
	IntSlice s;
	s.len = len;
	s.arr = malloc(len * sizeof(int));
	return s;
}

void freeIntSlice(IntSlice s) {
	free(s.arr);
}

int intSliceLen(IntSlice s) {
	return s.len;
}

int intSliceLess(IntSlice s, int i, int j) {
	return s.arr[i] < s.arr[j];
}

void intSliceSwap(IntSlice s, int i, int j) {
	int tmp = s.arr[i];
	s.arr[i] = s.arr[j];
	s.arr[j] = tmp;
}

void intSliceSort(IntSlice s) {
	qsort(s.arr, s.len, sizeof(int), intSliceLess);
}

typedef struct {
	int len;
	int *arr;
} IntSlice;

IntSlice newIntSlice(int len) {
	IntSlice s;
	s.len = len;
	s.arr = malloc(len * sizeof(int));
	return s;
}

void freeIntSlice(IntSlice s) {
	free(s.arr);
}

int intSliceLen(IntSlice s) {
	return s.len;
}

int intSliceLess(IntSlice s, int i, int j) {
	return s.arr[i] < s.arr[j];
}

void intSliceSwap(IntSlice s, int i, int j) {
	int tmp = s.arr[i];
	s.arr[i] = s.arr[j];
	s.arr[j] = tmp;
}

void intSliceSort(IntSlice s) {
	qsort(s.arr, s.len, sizeof(int), intSliceLess);
}

typedef struct {
	int len;
	int *arr;
} IntSlice;

IntSlice newIntSlice(int len) {
	IntSlice s;
	s.len = len;
	s.arr = malloc(len * sizeof(int));
	return s;
}

void freeIntSlice(IntSlice s) {
	free(s.arr);
}

int intSliceLen(IntSlice s) {
	return s.len;
}

int intSliceLess(IntSlice s, int i, int j) {
	return s.arr[i] < s.arr[j];
}

void intSliceSwap(IntSlice s, int i, int j) {
	int tmp = s.arr[i];
	s.arr[i] = s.arr[j];
	s.arr[j] = tmp;
}

void intSliceSort(IntSlice s) {
	qsort(s.arr, s.len, sizeof(int), intSliceLess);
}

typedef struct {
	int len;
	int *arr;
} IntSlice;

IntSlice newIntSlice(int len) {
	IntSlice s;
	s.len = len;
	s.arr = malloc(len * sizeof(int));
	return s;
}

void freeIntSlice(IntSlice s) {
	free(s.arr);
}

int intSliceLen(IntSlice s) {
	return s.len;
}

int intSliceLess(IntSlice s, int i, int j) {
	return s.arr[i] < s.arr[j];
}

void intSliceSwap(IntSlice s, int i, int j) {
	int tmp = s.arr[i];
	s.arr[i] = s.arr[j];
	s.arr[j] = tmp;
}

void intSliceSort(IntSlice s) {
	qsort(s.arr, s.len, sizeof(int), intSliceLess);
}

typedef struct {
	int len;
	int *arr;
} IntSlice;

IntSlice newIntSlice(int len) {
	IntSlice s;
	s.len = len;
	s.arr = malloc(len * sizeof(int));
	return s;
}

void freeIntSlice(IntSlice s) {
	free(s.arr);
}

int intSliceLen(IntSlice s) {
	return s.len;
}

int intSliceLess(IntSlice s, int i, int j) {
	return s.arr[i] < s.arr[j];
}

void intSliceSwap(IntSlice s, int i, int j) {
	int tmp = s.arr[i];
	s.arr[i] = s.arr[j];
	s.arr[j] = tmp;
}

void intSliceSort(IntSlice s) {
	qsort(s.arr, s.len, sizeof(int), intSliceLess);
}

typedef struct {
	int len;
	int *arr;
} IntSlice;

IntSlice newIntSlice(int len) {
	IntSlice s;
	s.len = len;
	s.arr = malloc(len * sizeof(int));
	return s;
}

void freeIntSlice(IntSlice s) {
	free(s.arr);
}

int intSliceLen(IntSlice s) {
	return s.len;
}

int intSliceLess(IntSlice s, int i, int j) {
	return s.arr[i] < s.arr[j];
}

void intSliceSwap(IntSlice s, int i, int j) {
	int tmp = s.arr[i];
	s.arr[i] = s.arr[j];
	s.arr[j] = tmp;
}

void intSliceSort(IntSlice s) {
	qsort(s.arr, s.len, sizeof(int), intSliceLess);
}

typedef struct {
	int len;
	int *arr;
} IntSlice;

IntSlice newIntSlice(int len) {
	IntSlice s;
	s.len = len;
	s.arr = malloc(len * siz