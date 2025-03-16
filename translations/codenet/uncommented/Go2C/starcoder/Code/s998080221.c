#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX(x, y) ((x) > (y)? (x) : (y))
#define MIN(x, y) ((x) < (y)? (x) : (y))
#define ABS(x) ((x) < 0? -(x) : (x))
#define DIV_UP(x, y) (((x) + (y) - 1) / (y))
#define GCD(x, y) ((x) < (y)? gcd((y), (x)) : gcd((x), (y)))
#define LCM(x, y) ((x) * (y) / gcd((x), (y)))
#define POW(x, y) ((int64_t)pow((double)(x), (double)(y)))

typedef struct {
	int64_t i;
	int64_t buf[1024];
} bufReader;

bufReader reader;

void bufReaderInit(void) {
	reader.i = 0;
	memset(reader.buf, 0, sizeof(reader.buf));
	setbuf(stdin, NULL);
}

void bufReaderNext(void) {
	if (reader.i < sizeof(reader.buf)) {
		return;
	}
	reader.i = 0;
	memset(reader.buf, 0, sizeof(reader.buf));
	while (true) {
		char *line = NULL;
		size_t len = 0;
		if (getline(&line, &len, stdin) == -1) {
			free(line);
			exit(0);
		}
		if (len == 0) {
			free(line);
			exit(0);
		}
		if (len >= sizeof(reader.buf)) {
			free(line);
			continue;
		}
		memcpy(reader.buf, line, len);
		free(line);
		break;
	}
}

char *bufReaderNextLine(void) {
	bufReaderNext();
	char *s = reader.buf + reader.i;
	reader.i = sizeof(reader.buf);
	return s;
}

int64_t bufReaderNextInt64(void) {
	char *s = bufReaderNextLine();
	int64_t i = 0;
	int64_t neg = 1;
	if (*s == '-') {
		neg = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9') {
		i = i * 10 + (*s - '0');
		s++;
	}
	return i * neg;
}

int bufReaderNextInt(void) {
	return (int)bufReaderNextInt64();
}

int main(void) {
	bufReaderInit();
	int N = bufReaderNextInt();
	int _ = bufReaderNextInt();
	int A[N];
	for (int i = 0; i < N; i++) {
		A[i] = bufReaderNextInt();
	}
	int maxProfit = 0;
	int maxCnt = 0;
	int maxA = A[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		int profit = MAX(0, maxA - A[i]);
		if (maxProfit < profit) {
			maxProfit = profit;
			maxCnt = 1;
		} else if (maxProfit == profit) {
			maxCnt++;
		}
		maxA = MAX(maxA, A[i]);
	}
	printf("%d\n", maxCnt);
	return 0;
}

