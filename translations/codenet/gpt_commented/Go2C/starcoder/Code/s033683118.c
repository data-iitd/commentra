

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string reads the next string from the provided file pointer.
// It allocates a buffer for the string and returns a pointer to the string.
// The caller is responsible for freeing the returned string.
char* get_next_string(FILE* fp) {
	char* str = NULL;
	int len = 0;
	int cap = 0;
	int c = 0;
	for (c = getc(fp); c!= EOF && c!= '\n'; c = getc(fp)) {
		if (len == cap) {
			cap = (cap == 0)? 1 : (cap * 2);
			str = realloc(str, cap);
		}
		str[len++] = c;
	}
	if (c == EOF && len == 0) {
		return NULL;
	}
	str[len] = '\0';
	return str;
}

// get_next_int reads the next integer from the provided file pointer.
// It returns the integer and an error value.
int get_next_int(FILE* fp) {
	int val = 0;
	int neg = 0;
	int c = 0;
	for (c = getc(fp); c!= EOF && c!= '\n'; c = getc(fp)) {
		if (c == '-') {
			neg = 1;
		} else if (c >= '0' && c <= '9') {
			val = (val * 10) + (c - '0');
		}
	}
	if (neg) {
		val = -val;
	}
	return val;
}

// get_next_float reads the next float from the provided file pointer.
// It returns the float and an error value.
float get_next_float(FILE* fp) {
	float val = 0.0;
	int neg = 0;
	int c = 0;
	for (c = getc(fp); c!= EOF && c!= '\n'; c = getc(fp)) {
		if (c == '-') {
			neg = 1;
		} else if (c >= '0' && c <= '9') {
			val = (val * 10) + (c - '0');
		}
	}
	if (neg) {
		val = -val;
	}
	return val;
}

int main(int argc, char* argv[]) {
	// Initialize file pointers for input and output.
	FILE* fp = stdin;
	FILE* wfp = stdout;
	int cnt = 0;

	// Check for environment variables to determine input and output files.
	if (getenv("MASPY") == "ますピ") {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
		cnt = 2; // Set the count for additional processing.
	}
	if (getenv("MASPYPY") == "ますピッピ") {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	}

	// Solve the problem for the first time.
	solve(fp, wfp);

	// If cnt is greater than 0, solve the problem additional times.
	for (int i = 0; i < cnt; i++) {
		fprintf(wfp, "-----------------------------------\n");
		solve(fp, wfp);
	}

	// Flush the writer to ensure all output is written.
	fflush(wfp);
}

// solve processes the input values and determines if the condition is met.
// It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
void solve(FILE* fp, FILE* wfp) {
	int k = get_next_int(fp); // Read the first integer k.
	int x = get_next_int(fp); // Read the second integer x.

	char* ans = "No"; // Default answer is "No".
	if (k * 500 >= x) { // Check the condition.
		ans = "Yes"; // Update answer to "Yes" if condition is met.
	}
	fprintf(wfp, "%s\n", ans); // Output the result.
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string reads the next string from the provided file pointer.
// It allocates a buffer for the string and returns a pointer to the string.
// The caller is responsible for freeing the returned string.
char* get_next_string(FILE* fp) {
	char* str = NULL;
	int len = 0;
	int cap = 0;
	int c = 0;
	for (c = getc(fp); c!= EOF && c!= '\n'; c = getc(fp)) {
		if (len == cap) {
			cap = (cap == 0)? 1 : (cap * 2);
			str = realloc(str, cap);
		}
		str[len++] = c;
	}
	if (c == EOF && len == 0) {
		return NULL;
	}
	str[len] = '\0';
	return str;
}

// get_next_int reads the next integer from the provided file pointer.
// It returns the integer and an error value.
int get_next_int(FILE* fp) {
	int val = 0;
	int neg = 0;
	int c = 0;
	for (c = getc(fp); c!= EOF && c!= '\n'; c = getc(fp)) {
		if (c == '-') {
			neg = 1;
		} else if (c >= '0' && c <= '9') {
			val = (val * 10) + (c - '0');
		}
	}
	if (neg) {
		val = -val;
	}
	return val;
}

// get_next_float reads the next float from the provided file pointer.
// It returns the float and an error value.
float get_next_float(FILE* fp) {
	float val = 0.0;
	int neg = 0;
	int c = 0;
	for (c = getc(fp); c!= EOF && c!= '\n'; c = getc(fp)) {
		if (c == '-') {
			neg = 1;
		} else if (c >= '0' && c <= '9') {
			val = (val * 10) + (c - '0');
		}
	}
	if (neg) {
		val = -val;
	}
	return val;
}

int main(int argc, char* argv[]) {
	// Initialize file pointers for input and output.
	FILE* fp = stdin;
	FILE* wfp = stdout;
	int cnt = 0;

	// Check for environment variables to determine input and output files.
	if (getenv("MASPY") == "ますピ") {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
		cnt = 2; // Set the count for additional processing.
	}
	if (getenv("MASPYPY") == "ますピッピ") {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	}

	// Solve the problem for the first time.
	solve(fp, wfp);

	// If cnt is greater than 0, solve the problem additional times.
	for (int i = 0; i < cnt; i++) {
		fprintf(wfp, "-----------------------------------\n");
		solve(fp, wfp);
	}

	// Flush the writer to ensure all output is written.
	fflush(wfp);
}

// solve processes the input values and determines if the condition is met.
// It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
void solve(FILE* fp, FILE* wfp) {
	int k = get_next_int(fp); // Read the first integer k.
	int x = get_next_int(fp); // Read the second integer x.

	char* ans = "No"; // Default answer is "No".
	if (k * 500 >= x) { // Check the condition.
		ans = "Yes"; // Update answer to "Yes" if condition is met.
	}
	fprintf(wfp, "%s\n", ans); // Output the result.
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string reads the next string from the provided file pointer.
// It allocates a buffer for the string and returns a pointer to the string.
// The caller is responsible for freeing the returned string.
char* get_next_string(FILE* fp) {
	char* str = NULL;
	int len = 0;
	int cap = 0;
	int c = 0;
	for (c = getc(fp); c!= EOF && c!= '\n'; c = getc(fp)) {
		if (len == cap) {
			cap = (cap == 0)? 1 : (cap * 2);
			str = realloc(str, cap);
		}
		str[len++] = c;
	}
	if (c == EOF && len == 0) {
		return NULL;
	}
	str[len] = '\0';
	return str;
}

// get_next_int reads the next integer from the provided file pointer.
// It returns the integer and an error value.
int get_next_int(FILE* fp) {
	int val = 0;
	int neg = 0;
	int c = 0;
	for (c = getc(fp); c!= EOF && c!= '\n'; c = getc(fp)) {
		if (c == '-') {
			neg = 1;
		} else if (c >= '0' && c <= '9') {
			val = (val * 10) + (c - '0');
		}
	}
	if (neg) {
		val = -val;
	}
	return val;
}

// get_next_float reads the next float from the provided file pointer.
// It returns the float and an error value.
float get_next_float(FILE* fp) {
	float val = 0.0;
	int neg = 0;
	int c = 0;
	for (c = getc(fp); c!= EOF && c!= '\n'; c = getc(fp)) {
		if (c == '-') {
			neg = 1;
		} else if (c >= '0' && c <= '9') {
			val = (val * 10) + (c - '0');
		}
	}
	if (neg) {
		val = -val;
	}
	return val;
}

int main(int argc, char* argv[]) {
	// Initialize file pointers for input and output.
	FILE* fp = stdin;
	FILE* wfp = stdout;
	int cnt = 0;

	// Check for environment variables to determine input and output files.
	if (getenv("MASPY") == "ますピ") {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
		cnt = 2; // Set the count for additional processing.
	}
	if (getenv("MASPYPY") == "ますピッピ") {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	}

	// Solve the problem for the first time.
	solve(fp, wfp);

	// If cnt is greater than 0, solve the problem additional times.
	for (int i = 0; i < cnt; i++) {
		fprintf(wfp, "-----------------------------------\n");
		solve(fp, wfp);
	}

	// Flush the writer to ensure all output is written.
	fflush(wfp);
}

// solve processes the input values and determines if the condition is met.
// It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
void solve(FILE* fp, FILE* wfp) {
	int k = get_next_int(fp); // Read the first integer k.
	int x = get_next_int(fp); // Read the second integer x.

	char* ans = "No"; // Default answer is "No".
	if (k * 500 >= x) { // Check the condition.
		ans = "Yes"; // Update answer to "Yes" if condition is met.
	}
	fprintf(wfp, "%s\n", ans); // Output the result.
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string reads the next string from the provided file pointer.
// It allocates a buffer for the string and returns a pointer to the string.
// The caller is responsible for freeing the returned string.
char* get_next_string(FILE* fp) {
	char* str = NULL;
	int len = 0;
	int cap = 0;
	int c = 0;
	for (c = getc(fp); c!= EOF && c!= '\n'; c = getc(fp)) {
		if (len == cap) {
			cap = (cap == 0)? 1 : (cap * 2);
			str = realloc(str, cap);
		}
		str[len++] = c;
	}
	if (c == EOF && len == 0) {
		return NULL;
	}
	str[len] = '\0';
	return str;
}

// get_next_int reads the next integer from the provided file pointer.
// It returns the integer and an error value.
int get_next_int(FILE* fp) {
	int val = 0;
	int neg = 0;
	int c = 0;
	for (c = getc(fp); c!= EOF && c!= '\n'; c = getc(fp)) {
		if (c == '-') {
			neg = 1;
		} else if (c >= '0' && c <= '9') {
			val = (val * 10) + (c - '0');
		}
	}
	if (neg) {
		val = -val;
	}
	return val;
}

// get_next_float reads the next float from the provided file pointer.
// It returns the float and an error value.
float get_next_float(FILE* fp) {
	float val = 0.0;
	int neg = 0;
	int c = 0;
	for (c = getc(fp); c!= EOF && c!= '\n'; c = getc(fp)) {
		if (c == '-') {
			neg = 1;
		} else if (c >= '0' && c <= '9') {
			val = (val * 10) + (c - '0');
		}
	}
	if (neg) {
		val = -val;
	}
	return val;
}

int main(int argc, char* argv[]) {
	// Initialize file pointers for input and output.
	FILE* fp = stdin;
	FILE* wfp = stdout;
	int cnt = 0;

	// Check for environment variables to determine input and output files.
	if (getenv("MASPY") == "ますピ") {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
		cnt = 2; // Set the count for additional processing.
	}
	if (getenv("MASPYPY") == "ますピッピ") {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	}

	// Solve the problem for the first time.
	solve(fp, wfp);
