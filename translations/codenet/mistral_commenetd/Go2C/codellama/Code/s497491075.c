
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function Run calculates the number of points within a square with side length D and center at (0,0)
void Run(FILE *r, FILE *w) {
	// Initialize a new scanner object to read input
	Scanner sc = NewScanner(r);

	// Read the first line of input containing N and D
	int N, D;
	fscanf(r, "%d %d", &N, &D);

	// Read N lines of input and store them in a slice called lines
	int lines[N][2];
	for (int i = 0; i < N; i++) {
		fscanf(r, "%d %d", &lines[i][0], &lines[i][1]);
	}

	// Initialize a counter variable count to 0
	int count = 0;

	// Iterate through each line in the lines slice
	for (int i = 0; i < N; i++) {
		// Calculate the Euclidean distance of the current line from the origin (0,0)
		double d = sqrt(lines[i][0]*lines[i][0] + lines[i][1]*lines[i][1]);

		// If the distance of the current line is less than or equal to D, increment the counter
		if (D >= d) {
			count++;
		}
	}

	// Write the final result to the output writer
	fprintf(w, "%d\n", count);
}

// Function NewScanner initializes a new scanner object
Scanner NewScanner(FILE *r) {
	// Initialize a new scanner object
	Scanner sc;
	sc.r = r;
	return sc;
}

// Scanner structure to read input lines
typedef struct {
	FILE *r;
} Scanner;

// ReadLine function reads a single line of input and returns it as a Value object
Value ReadLine(Scanner sc) {
	// Read a line using the scanner and return it as a Value object
	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, sc.r);
	Value v = line;
	free(line);
	return v;
}

// ReadLines function reads N lines of input and returns them as a slice of Value objects
Values ReadLines(Scanner sc, int N) {
	// Initialize an empty slice called a and append N Value objects to it
	Values a;
	for (int i = 0; i < N; i++) {
		// Read a single line and append it to the slice
		a = append(a, ReadLine(sc));
	}
	// Return the slice of Value objects
	return a;
}

// Value structure to store a string value
typedef char *Value;

// String function returns the string representation of the Value object
char *String(Value v) {
	return v;
}

// Int function converts a Value object to an integer
int Int(Value v) {
	// Parse the string representation of the Value object to an integer and return it
	int n = atoi(v);
	return n;
}

// Float64 function converts a Value object to a float64
double Float64(Value v) {
	// Parse the string representation of the Value object to a float64 and return it
	double f = atof(v);
	return f;
}

// Strings function splits a Value object into a slice of strings based on whitespace
char **Strings(Value v) {
	// Split the string representation of the Value object based on whitespace and return the slice
	char *line = String(v);
	char *token = strtok(line, " ");
	char **a = malloc(sizeof(char *) * 100);
	int i = 0;
	while (token != NULL) {
		a[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	return a;
}

// Ints function converts a Value object to a slice of integers
int *Ints(Value v) {
	// Convert each string in the slice returned by the Strings function to an integer and return the slice
	char **a = Strings(v);
	int *b = malloc(sizeof(int) * 100);
	int i = 0;
	while (a[i] != NULL) {
		b[i] = atoi(a[i]);
		i++;
	}
	return b;
}

// Float64s function converts a Value object to a slice of float64s
double *Float64s(Value v) {
	// Parse each string in the slice returned by the Strings function to a float64 and return the slice
	char **a = Strings(v);
	double *b = malloc(sizeof(double) * 100);
	int i = 0;
	while (a[i] != NULL) {
		b[i] = atof(a[i]);
		i++;
	}
	return b;
}

// Runes function converts a Value object to a slice of runes
rune *Runes(Value v) {
	// Convert the string representation of the Value object to a slice of runes and return it
	char *line = String(v);
	rune *a = malloc(sizeof(rune) * 100);
	int i = 0;
	while (line[i] != '\0') {
		a[i] = line[i];
		i++;
	}
	return a;
}

// Values structure to store a slice of Value objects
typedef struct {
	Value *a;
	int n;
} Values;

// Strings function returns a slice of slices of strings, where each inner slice corresponds to the strings in a single Value object
char ***Strings(Values v) {
	// Convert each Value object to a slice of strings and return the outer slice
	char ***a = malloc(sizeof(char **) * 100);
	int i = 0;
	while (v.a[i] != NULL) {
		a[i] = Strings(v.a[i]);
		i++;
	}
	return a;
}

// Ints function returns a slice of slices of integers, where each inner slice corresponds to the integers in a single Value object
int **Ints(Values v) {
	// Convert each Value object to a slice of integers and return the outer slice
	int **a = malloc(sizeof(int *) * 100);
	int i = 0;
	while (v.a[i] != NULL) {
		a[i] = Ints(v.a[i]);
		i++;
	}
	return a;
}

// Float64s function returns a slice of slices of float64s, where each inner slice corresponds to the float64s in a single Value object
double **Float64s(Values v) {
	// Convert each Value object to a slice of float64s and return the outer slice
	double **a = malloc(sizeof(double *) * 100);
	int i = 0;
	while (v.a[i] != NULL) {
		a[i] = Float64s(v.a[i]);
		i++;
	}
	return a;
}

// Runes function returns a slice of slices of runes, where each inner slice corresponds to the runes in a single Value object
rune **Runes(Values v) {
	// Convert each Value object to a slice of runes and return the outer slice
	rune **a = malloc(sizeof(rune *) * 100);
	int i = 0;
	while (v.a[i] != NULL) {
		a[i] = Runes(v.a[i]);
		i++;
	}
	return a;
}

// main function calls the Run function with standard input and output streams
int main() {
	Run(stdin, stdout);
	return 0;
}

