#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Run function processes input from the reader and writes output to the writer
void Run(FILE *r, FILE *w) {
	// Initialize a new scanner to read input
	Scanner *sc = NewScanner(r);

	// Read the first line of input and parse N (number of lines) and D (distance threshold)
	int a[2];
	fscanf(r, "%d %d", &a[0], &a[1]);
	int N = a[0], D = a[1];

	// Read the next N lines of input, each containing a pair of integers
	int lines[N][2];
	for (int i = 0; i < N; i++) {
		fscanf(r, "%d %d", &lines[i][0], &lines[i][1]);
	}

	// Initialize a counter for the number of points within the distance D
	int count = 0;
	// Iterate over each line of input
	for (int i = 0; i < N; i++) {
		// Calculate the Euclidean distance from the origin (0, 0)
		double d = sqrt(lines[i][0]*lines[i][0] + lines[i][1]*lines[i][1]);
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
	FILE *sc;
} Scanner;

// NewScanner initializes a new Scanner with the provided io.Reader
Scanner *NewScanner(FILE *r) {
	Scanner *sc = (Scanner *)malloc(sizeof(Scanner));
	sc->sc = r;
	return sc;
}

// ReadLine reads a single line from the input and returns it as a Value
Value *ReadLine(Scanner *s) {
	char *line = NULL;
	size_t len = 0;
	ssize_t n = getline(&line, &len, s->sc);
	if (n == -1) {
		free(line);
		exit(1);
	}
	Value *v = (Value *)malloc(sizeof(Value));
	v->str = line;
	v->len = len;
	return v;
}

// ReadLines reads n lines from the input and returns them as Values
Values *ReadLines(Scanner *s, int n) {
	Values *v = (Values *)malloc(sizeof(Values));
	v->len = n;
	v->vals = (Value **)malloc(sizeof(Value *) * n);
	for (int i = 0; i < n; i++) {
		v->vals[i] = ReadLine(s);
	}
	return v;
}

// Value type represents a string value with additional methods for conversion
typedef struct {
	char *str;
	size_t len;
} Value;

// String returns the string representation of the Value
char *String(Value *v) {
	return v->str;
}

// Int converts the Value to an integer
int Int(Value *v) {
	int n = atoi(v->str);
	return n;
}

// Float64 converts the Value to a float64
double Float64(Value *v) {
	double f = atof(v->str);
	return f;
}

// Strings splits the Value into a slice of strings
char **Strings(Value *v) {
	char **a = (char **)malloc(sizeof(char *) * 2);
	a[0] = strtok(v->str, " ");
	a[1] = strtok(NULL, " ");
	return a;
}

// Ints converts the Value to a slice of integers
int *Ints(Value *v) {
	char **a = Strings(v);
	int *b = (int *)malloc(sizeof(int) * 2);
	b[0] = atoi(a[0]);
	b[1] = atoi(a[1]);
	return b;
}

// Float64s converts the Value to a slice of float64
double *Float64s(Value *v) {
	char **a = Strings(v);
	double *b = (double *)malloc(sizeof(double) * 2);
	b[0] = atof(a[0]);
	b[1] = atof(a[1]);
	return b;
}

// Runes converts the Value to a slice of runes
rune *Runes(Value *v) {
	return (rune *)v->str;
}

// Values type represents a slice of Value
typedef struct {
	int len;
	Value **vals;
} Values;

// Strings converts the Values to a slice of string slices
char ***Strings(Values *v) {
	char ***a = (char ***)malloc(sizeof(char **) * v->len);
	for (int i = 0; i < v->len; i++) {
		a[i] = Strings(v->vals[i]);
	}
	return a;
}

// Ints converts the Values to a slice of integer slices
int **Ints(Values *v) {
	int **a = (int **)malloc(sizeof(int *) * v->len);
	for (int i = 0; i < v->len; i++) {
		a[i] = Ints(v->vals[i]);
	}
	return a;
}

// Float64s converts the Values to a slice of float64 slices
double **Float64s(Values *v) {
	double **a = (double **)malloc(sizeof(double *) * v->len);
	for (int i = 0; i < v->len; i++) {
		a[i] = Float64s(v->vals[i]);
	}
	return a;
}

// Runes converts the Values to a slice of rune slices
rune **Runes(Values *v) {
	rune **a = (rune **)malloc(sizeof(rune *) * v->len);
	for (int i = 0; i < v->len; i++) {
		a[i] = Runes(v->vals[i]);
	}
	return a;
}

// main function serves as the entry point of the program
int main() {
	// Call the Run function with standard input and output
	Run(stdin, stdout);
	return 0;
}

