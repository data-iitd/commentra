

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FastScanner is a structure for efficient input reading
typedef struct {
	char* buf;
	size_t pos;
	size_t len;
	FILE* in;
} FastScanner;

// NewFastScanner initializes and returns a new FastScanner
FastScanner* NewFastScanner() {
	FastScanner* fs = malloc(sizeof(FastScanner));
	fs->in = fopen(NULL, "r");
	fs->buf = NULL;
	fs->pos = 0;
	fs->len = 0;
	return fs;
}

// Next reads the next token from the input
char* Next(FastScanner* fs) {
	if (fs->buf == NULL) {
		fs->buf = malloc(1024);
		fs->len = fread(fs->buf, 1, 1024, fs->in);
		fs->pos = 0;
	}
	while (fs->pos < fs->len) {
		if (fs->buf[fs->pos] =='') {
			fs->pos++;
			return &fs->buf[fs->pos];
		}
		fs->pos++;
	}
	return NULL;
}

// NextLine reads the next line from the input
char* NextLine(FastScanner* fs) {
	if (fs->buf == NULL) {
		fs->buf = malloc(1024);
		fs->len = fread(fs->buf, 1, 1024, fs->in);
		fs->pos = 0;
	}
	while (fs->pos < fs->len) {
		if (fs->buf[fs->pos] == '\n') {
			fs->pos++;
			return &fs->buf[fs->pos];
		}
		fs->pos++;
	}
	return NULL;
}

// NextInt reads the next integer from the input
int NextInt(FastScanner* fs) {
	char* token = Next(fs);
	if (token == NULL) {
		return 0;
	}
	return atoi(token);
}

// NextInt64 reads the next int64 from the input
int64_t NextInt64(FastScanner* fs) {
	char* token = Next(fs);
	if (token == NULL) {
		return 0;
	}
	return atoll(token);
}

// IntMax returns the maximum of two integers
int IntMax(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Int64Max returns the maximum of two int64 values
int64_t Int64Max(int64_t a, int64_t b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Float64Max returns the maximum of two float64 values
double Float64Max(double a, double b) {
	if (a < b) {
		return b;
	}
	return a;
}

// IntMin returns the minimum of two integers
int IntMin(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Int64Min returns the minimum of two int64 values
int64_t Int64Min(int64_t a, int64_t b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Float64Min returns the minimum of two float64 values
double Float64Min(double a, double b) {
	if (a > b) {
		return b;
	}
	return a;
}

// IntGcd computes the greatest common divisor of two integers
int IntGcd(int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0) {
		return a;
	}
	return IntGcd(b, a % b);
}

// Int64Gcd computes the greatest common divisor of two int64 values
int64_t Int64Gcd(int64_t a, int64_t b) {
	if (a < b) {
		int64_t tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0) {
		return a;
	}
	return Int64Gcd(b, a % b);
}

// IntAbs returns the absolute value of an integer
int IntAbs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

// Int64Abs returns the absolute value of an int64
int64_t Int64Abs(int64_t a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

int main() {
	// Initialize a new FastScanner to read input
	FastScanner* fsc = NewFastScanner();
	// Read three integers A, B, and C from input
	int A = NextInt(fsc);
	int B = NextInt(fsc);
	int C = NextInt(fsc);
	// Check if the difference between B and A is equal to the difference between C and B
	if (B - A == C - B) {
		// If the differences are equal, print "YES"
		printf("YES\n");
	} else {
		// Otherwise, print "NO"
		printf("NO\n");
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FastScanner is a structure for efficient input reading
typedef struct {
	char* buf;
	size_t pos;
	size_t len;
	FILE* in;
} FastScanner;

// NewFastScanner initializes and returns a new FastScanner
FastScanner* NewFastScanner() {
	FastScanner* fs = malloc(sizeof(FastScanner));
	fs->in = fopen(NULL, "r");
	fs->buf = NULL;
	fs->pos = 0;
	fs->len = 0;
	return fs;
}

// Next reads the next token from the input
char* Next(FastScanner* fs) {
	if (fs->buf == NULL) {
		fs->buf = malloc(1024);
		fs->len = fread(fs->buf, 1, 1024, fs->in);
		fs->pos = 0;
	}
	while (fs->pos < fs->len) {
		if (fs->buf[fs->pos] =='') {
			fs->pos++;
			return &fs->buf[fs->pos];
		}
		fs->pos++;
	}
	return NULL;
}

// NextLine reads the next line from the input
char* NextLine(FastScanner* fs) {
	if (fs->buf == NULL) {
		fs->buf = malloc(1024);
		fs->len = fread(fs->buf, 1, 1024, fs->in);
		fs->pos = 0;
	}
	while (fs->pos < fs->len) {
		if (fs->buf[fs->pos] == '\n') {
			fs->pos++;
			return &fs->buf[fs->pos];
		}
		fs->pos++;
	}
	return NULL;
}

// NextInt reads the next integer from the input
int NextInt(FastScanner* fs) {
	char* token = Next(fs);
	if (token == NULL) {
		return 0;
	}
	return atoi(token);
}

// NextInt64 reads the next int64 from the input
int64_t NextInt64(FastScanner* fs) {
	char* token = Next(fs);
	if (token == NULL) {
		return 0;
	}
	return atoll(token);
}

// IntMax returns the maximum of two integers
int IntMax(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Int64Max returns the maximum of two int64 values
int64_t Int64Max(int64_t a, int64_t b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Float64Max returns the maximum of two float64 values
double Float64Max(double a, double b) {
	if (a < b) {
		return b;
	}
	return a;
}

// IntMin returns the minimum of two integers
int IntMin(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Int64Min returns the minimum of two int64 values
int64_t Int64Min(int64_t a, int64_t b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Float64Min returns the minimum of two float64 values
double Float64Min(double a, double b) {
	if (a > b) {
		return b;
	}
	return a;
}

// IntGcd computes the greatest common divisor of two integers
int IntGcd(int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0) {
		return a;
	}
	return IntGcd(b, a % b);
}

// Int64Gcd computes the greatest common divisor of two int64 values
int64_t Int64Gcd(int64_t a, int64_t b) {
	if (a < b) {
		int64_t tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0) {
		return a;
	}
	return Int64Gcd(b, a % b);
}

// IntAbs returns the absolute value of an integer
int IntAbs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

// Int64Abs returns the absolute value of an int64
int64_t Int64Abs(int64_t a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

int main() {
	// Initialize a new FastScanner to read input
	FastScanner* fsc = NewFastScanner();
	// Read three integers A, B, and C from input
	int A = NextInt(fsc);
	int B = NextInt(fsc);
	int C = NextInt(fsc);
	// Check if the difference between B and A is equal to the difference between C and B
	if (B - A == C - B) {
		// If the differences are equal, print "YES"
		printf("YES\n");
	} else {
		// Otherwise, print "NO"
		printf("NO\n");
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FastScanner is a structure for efficient input reading
typedef struct {
	char* buf;
	size_t pos;
	size_t len;
	FILE* in;
} FastScanner;

// NewFastScanner initializes and returns a new FastScanner
FastScanner* NewFastScanner() {
	FastScanner* fs = malloc(sizeof(FastScanner));
	fs->in = fopen(NULL, "r");
	fs->buf = NULL;
	fs->pos = 0;
	fs->len = 0;
	return fs;
}

// Next reads the next token from the input
char* Next(FastScanner* fs) {
	if (fs->buf == NULL) {
		fs->buf = malloc(1024);
		fs->len = fread(fs->buf, 1, 1024, fs->in);
		fs->pos = 0;
	}
	while (fs->pos < fs->len) {
		if (fs->buf[fs->pos] =='') {
			fs->pos++;
			return &fs->buf[fs->pos];
		}
		fs->pos++;
	}
	return NULL;
}

// NextLine reads the next line from the input
char* NextLine(FastScanner* fs) {
	if (fs->buf == NULL) {
		fs->buf = malloc(1024);
		fs->len = fread(fs->buf, 1, 1024, fs->in);
		fs->pos = 0;
	}
	while (fs->pos < fs->len) {
		if (fs->buf[fs->pos] == '\n') {
			fs->pos++;
			return &fs->buf[fs->pos];
		}
		fs->pos++;
	}
	return NULL;
}

// NextInt reads the next integer from the input
int NextInt(FastScanner* fs) {
	char* token = Next(fs);
	if (token == NULL) {
		return 0;
	}
	return atoi(token);
}

// NextInt64 reads the next int64 from the input
int64_t NextInt64(FastScanner* fs) {
	char* token = Next(fs);
	if (token == NULL) {
		return 0;
	}
	return atoll(token);
}

// IntMax returns the maximum of two integers
int IntMax(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Int64Max returns the maximum of two int64 values
int64_t Int64Max(int64_t a, int64_t b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Float64Max returns the maximum of two float64 values
double Float64Max(double a, double b) {
	if (a < b) {
		return b;
	}
	return a;
}

// IntMin returns the minimum of two integers
int IntMin(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Int64Min returns the minimum of two int64 values
int64_t Int64Min(int64_t a, int64_t b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Float64Min returns the minimum of two float64 values
double Float64Min(double a, double b) {
	if (a > b) {
		return b;
	}
	return a;
}

// IntGcd computes the greatest common divisor of two integers
int IntGcd(int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0) {
		return a;
	}
	return IntGcd(b, a % b);
}

// Int64Gcd computes the greatest common divisor of two int64 values
int64_t Int64Gcd(int64_t a, int64_t b) {
	if (a < b) {
		int64_t tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0) {
		return a;
	}
	return Int64Gcd(b, a % b);
}

// IntAbs returns the absolute value of an integer
int IntAbs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

// Int64Abs returns the absolute value of an int64
int64_t Int64Abs(int64_t a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

int main() {
	// Initialize a new FastScanner to read input
	FastScanner* fsc = NewFastScanner();
	// Read three integers A, B, and C from input
	int A = NextInt(fsc);
	int B = NextInt(fsc);
	int C = NextInt(fsc);
	// Check if the difference between B and A is equal to the difference between C and B
	if (B - A == C - B) {
		// If the differences are equal, print "YES"
		printf("YES\n");
	} else {
		// Otherwise, print "NO"
		printf("NO\n")