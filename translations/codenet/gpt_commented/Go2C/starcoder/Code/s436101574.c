

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

// Function to scan a single string from input
char* scanString() {
	char* s = NULL;
	scanf("%ms", &s);
	return s;
}

// Function to scan a slice of runes from input
char* scanRunes() {
	char* s = NULL;
	scanf("%ms", &s);
	return s;
}

// Function to scan a single integer from input
int scanInt() {
	int a = 0;
	scanf("%d", &a);
	return a;
}

// Function to scan a single int64 from input
int64_t scanInt64() {
	int64_t a = 0;
	scanf("%" PRId64, &a);
	return a;
}

// Function to scan a single float64 from input
double scanFloat64() {
	double a = 0;
	scanf("%lf", &a);
	return a;
}

// Function to scan n integers from input and return them as a slice
int* scanInts(int n) {
	int* res = (int*) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &res[i]);
	}
	return res;
}

// Function to return the absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// Function to return the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to return the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Function to return the number of occurrences of a substring in a string
int count(char* s, char* t) {
	int c = 0;
	int i = 0;
	while (s[i]!= '\0') {
		if (s[i] == t[0]) {
			int j = 0;
			while (s[i+j] == t[j] && t[j]!= '\0') {
				j++;
			}
			if (t[j] == '\0') {
				c++;
			}
		}
		i++;
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRune(char* s, char t) {
	int c = 0;
	int i = 0;
	while (s[i]!= '\0') {
		if (s[i] == t) {
			c++;
		}
		i++;
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice2(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice3(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice4(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice5(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice6(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice7(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice8(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice9(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice10(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice11(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice12(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice13(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice14(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice15(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice16(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice17(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice18(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice19(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice20(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice21(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice22(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice23(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice24(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice25(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice26(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice27(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice28(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice29(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice30(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice31(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice32(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice33(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice34(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice35(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string
int countRuneSlice36(char* s, char t) {
	int c = 0;
	for (int i = 0; s[i]!= '\0'; i++) {
		if (s[i] == t) {
			c++;
		}
	}
	return c;
}

// Function to return the number of occurrences of a rune in a string