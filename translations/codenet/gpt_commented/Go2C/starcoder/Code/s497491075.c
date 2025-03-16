

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Run function processes input from the reader and writes output to the writer
void Run(FILE* r, FILE* w) {
	// Initialize a new scanner to read input
	Scanner* sc = NewScanner(r);

	// Read the first line of input and parse N (number of lines) and D (distance threshold)
	int* a = sc->ReadLine().Ints();
	int N = a[0];
	int D = a[1];

	// Read the next N lines of input, each containing a pair of integers
	Values lines = sc->ReadLines(N).Ints();

	// Initialize a counter for the number of points within the distance D
	int count = 0;
	// Iterate over each line of input
	for (int i = 0; i < lines.Length(); i++) {
		// Calculate the Euclidean distance from the origin (0, 0)
		float d = sqrt(lines[i][0] * lines[i][0] + lines[i][1] * lines[i][1]);
		// Check if the distance is less than or equal to D
		if (D >= d) {
			count++; // Increment the count if within distance
		}
	}
	// Output the total count of points within distance D
	fprintf(w, "%d\n", count);
}

// Scanner struct wraps bufio.Scanner for reading input
typedef struct {
	FILE* r;
	char* buf;
	int cap;
	int len;
	int pos;
} Scanner;

// NewScanner initializes a new Scanner with the provided io.Reader
Scanner* NewScanner(FILE* r) {
	Scanner* sc = malloc(sizeof(Scanner));
	sc->r = r;
	sc->buf = NULL;
	sc->cap = 0;
	sc->len = 0;
	sc->pos = 0;
	return sc;
}

// ReadLine reads a single line from the input and returns it as a Value
Value ReadLine(Scanner* sc) {
	if (sc->buf == NULL) {
		sc->buf = malloc(1024);
		sc->cap = 1024;
	}
	if (sc->pos == sc->len) {
		sc->pos = 0;
		sc->len = fread(sc->buf, 1, sc->cap, sc->r);
		if (sc->len == 0) {
			return NULL;
		}
	}
	int i = sc->pos;
	while (sc->buf[i]!= '\n' && i < sc->len) {
		i++;
	}
	int n = i - sc->pos + 1;
	char* s = malloc(n + 1);
	memcpy(s, sc->buf + sc->pos, n);
	s[n] = '\0';
	sc->pos = i + 1;
	return Value(s);
}

// ReadLines reads n lines from the input and returns them as Values
Values ReadLines(Scanner* sc, int n) {
	Values a = Values();
	for (int i = 0; i < n; i++) {
		a = append(a, ReadLine(sc));
	}
	return a;
}

// Value type represents a string value with additional methods for conversion
typedef struct {
	char* s;
} Value;

// String returns the string representation of the Value
char* String(Value v) {
	return v.s;
}

// Int converts the Value to an integer
int Int(Value v) {
	return atoi(v.s);
}

// Float64 converts the Value to a float64
float64 Float64(Value v) {
	return atof(v.s);
}

// Strings splits the Value into a slice of strings
char** Strings(Value v) {
	char** a = malloc(sizeof(char*) * 100);
	int n = 0;
	char* p = strtok(v.s, " ");
	while (p!= NULL) {
		a[n] = p;
		n++;
		p = strtok(NULL, " ");
	}
	return a;
}

// Ints converts the Value to a slice of integers
int* Ints(Value v) {
	int* a = malloc(sizeof(int) * 100);
	int n = 0;
	char* p = strtok(v.s, " ");
	while (p!= NULL) {
		a[n] = atoi(p);
		n++;
		p = strtok(NULL, " ");
	}
	return a;
}

// Float64s converts the Value to a slice of float64
float64* Float64s(Value v) {
	float64* a = malloc(sizeof(float64) * 100);
	int n = 0;
	char* p = strtok(v.s, " ");
	while (p!= NULL) {
		a[n] = atof(p);
		n++;
		p = strtok(NULL, " ");
	}
	return a;
}

// Runes converts the Value to a slice of runes
int* Runes(Value v) {
	int* a = malloc(sizeof(int) * 100);
	int n = 0;
	for (int i = 0; i < strlen(v.s); i++) {
		a[n] = v.s[i];
		n++;
	}
	return a;
}

// Values type represents a slice of Value
typedef struct {
	Value* a;
	int len;
	int cap;
} Values;

// Length returns the length of the Values
int Length(Values v) {
	return v.len;
}

// Get returns the element at the specified index
Value Get(Values v, int i) {
	return v.a[i];
}

// Set sets the element at the specified index
void Set(Values* v, int i, Value x) {
	v->a[i] = x;
}

// Append appends the element x to the Values
void Append(Values* v, Value x) {
	if (v->len == v->cap) {
		v->cap *= 2;
		v->a = realloc(v->a, sizeof(Value) * v->cap);
	}
	v->a[v->len] = x;
	v->len++;
}

// NewValues initializes and returns a new Values
Values NewValues(int n) {
	Values v;
	v.a = malloc(sizeof(Value) * n);
	v.len = 0;
	v.cap = n;
	return v;
}

// Run function processes input from the reader and writes output to the writer
void Run(FILE* r, FILE* w) {
	// Initialize a new scanner to read input
	Scanner* sc = NewScanner(r);

	// Read the first line of input and parse N (number of lines) and D (distance threshold)
	int* a = sc->ReadLine().Ints();
	int N = a[0];
	int D = a[1];

	// Read the next N lines of input, each containing a pair of integers
	Values lines = sc->ReadLines(N).Ints();

	// Initialize a counter for the number of points within the distance D
	int count = 0;
	// Iterate over each line of input
	for (int i = 0; i < lines.len; i++) {
		// Calculate the Euclidean distance from the origin (0, 0)
		float d = sqrt(lines.a[i][0] * lines.a[i][0] + lines.a[i][1] * lines.a[i][1]);
		// Check if the distance is less than or equal to D
		if (D >= d) {
			count++; // Increment the count if within distance
		}
	}
	// Output the total count of points within distance D
	fprintf(w, "%d\n", count);
}

// main function serves as the entry point of the program
int main() {
	// Call the Run function with standard input and output
	Run(stdin, stdout);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Run function processes input from the reader and writes output to the writer
void Run(FILE* r, FILE* w) {
	// Initialize a new scanner to read input
	Scanner* sc = NewScanner(r);

	// Read the first line of input and parse N (number of lines) and D (distance threshold)
	int* a = sc->ReadLine().Ints();
	int N = a[0];
	int D = a[1];

	// Read the next N lines of input, each containing a pair of integers
	Values lines = sc->ReadLines(N).Ints();

	// Initialize a counter for the number of points within the distance D
	int count = 0;
	// Iterate over each line of input
	for (int i = 0; i < lines.len; i++) {
		// Calculate the Euclidean distance from the origin (0, 0)
		float d = sqrt(lines.a[i][0] * lines.a[i][0] + lines.a[i][1] * lines.a[i][1]);
		// Check if the distance is less than or equal to D
		if (D >= d) {
			count++; // Increment the count if within distance
		}
	}
	// Output the total count of points within distance D
	fprintf(w, "%d\n", count);
}

// Scanner struct wraps bufio.Scanner for reading input
typedef struct {
	FILE* r;
	char* buf;
	int cap;
	int len;
	int pos;
} Scanner;

// NewScanner initializes a new Scanner with the provided io.Reader
Scanner* NewScanner(FILE* r) {
	Scanner* sc = malloc(sizeof(Scanner));
	sc->r = r;
	sc->buf = NULL;
	sc->cap = 0;
	sc->len = 0;
	sc->pos = 0;
	return sc;
}

// ReadLine reads a single line from the input and returns it as a Value
Value ReadLine(Scanner* sc) {
	if (sc->buf == NULL) {
		sc->buf = malloc(1024);
		sc->cap = 1024;
	}
	if (sc->pos == sc->len) {
		sc->pos = 0;
		sc->len = fread(sc->buf, 1, sc->cap, sc->r);
		if (sc->len == 0) {
			return NULL;
		}
	}
	int i = sc->pos;
	while (sc->buf[i]!= '\n' && i < sc->len) {
		i++;
	}
	int n = i - sc->pos + 1;
	char* s = malloc(n + 1);
	memcpy(s, sc->buf + sc->pos, n);
	s[n] = '\0';
	sc->pos = i + 1;
	return Value(s);
}

// ReadLines reads n lines from the input and returns them as Values
Values ReadLines(Scanner* sc, int n) {
	Values a = NewValues(n);
	for (int i = 0; i < n; i++) {
		a.a[i] = ReadLine(sc);
	}
	return a;
}

// Value type represents a string value with additional methods for conversion
typedef struct {
	char* s;
} Value;

// String returns the string representation of the Value
char* String(Value v) {
	return v.s;
}

// Int converts the Value to an integer
int Int(Value v) {
	return atoi(v.s);
}

// Float64 converts the Value to a float64
float64 Float64(Value v) {
	return atof(v.s);
}

// Strings splits the Value into a slice of strings
char** Strings(Value v) {
	char** a = malloc(sizeof(char*) * 100);
	int n = 0;
	char* p = strtok(v.s, " ");
	while (p!= NULL) {
		a[n] = p;
		n++;
		p = strtok(NULL, " ");
	}
	return a;
}

// Ints converts the Value to a slice of integers
int* Ints(Value v) {
	int* a = malloc(sizeof(int) * 100);
	int n = 0;
	char* p = strtok(v.s, " ");
	while (p!= NULL) {
		a[n] = atoi(p);
		n++;
		p = strtok(NULL, " ");
	}
	return a;
}

// Float64s converts the Value to a slice of float64
float64* Float64s(Value v) {
	float64* a = malloc(sizeof(float64) * 100);
	int n = 0;
	char* p = strtok(v.s, " ");
	while (p!= NULL) {
		a[n] = atof(p);
		n++;
		p = strtok(NULL, " ");
	}
	return a;
}

// Runes converts the Value to a slice of runes
int* Runes(Value v) {
	int* a = malloc(sizeof(int) * 100);
	int n = 0;
	for (int i = 0; i < strlen(v.s); i++) {
		a[n] = v.s[i];
		n++;
	}
	return a;
}

// Values type represents a slice of Value
typedef struct {
	Value* a;
	int len;
	int cap;
} Values;

// Length returns the length of the Values
int Length(Values v) {
	return v.len;
}

// Get returns the element at the specified index
Value Get(Values v, int i) {
	return v.a[i];
}

// Set sets the element at the specified index
void Set(Values* v, int i, Value x) {
	v->a[i] = x;
}

// Append appends the element x to the Values
void Append(Values* v, Value x) {
	if (v->len == v->cap) {
		v->cap *= 2;
		v->a = realloc(v->a, sizeof(Value) * v->cap);
	}
	v->a[v->len] = x;
	v->len++;
}

// NewValues initializes and returns a new Values
Values NewValues(int n) {
	Values v;
	v.a = malloc(sizeof(Value) * n);
	v.len = 0;
	v.cap = n;
	return v;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Run function processes input from the reader and writes output to the writer
void Run(FILE* r, FILE* w) {
	// Initialize a new scanner to read input
	Scanner* sc = NewScanner(r);

	// Read the first line of input and parse N (number of lines) and D (distance threshold)
	int* a = sc->ReadLine().Ints();
	int N = a[0];
	int D = a[1];

	// Read the next N lines of input, each contain