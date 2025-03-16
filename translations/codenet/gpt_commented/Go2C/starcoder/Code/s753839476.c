

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int AbsDiffFloat64(double n1, double n2);

// Main function
int main(void) {
	// Initialize input/output handling
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	if (in == NULL || out == NULL) {
		perror("An error occurred opening the file");
		exit(EXIT_FAILURE);
	}

	// Read the number of heights, target temperature, and actual temperature
	int n, t, a;
	fscanf(in, "%d %lf %lf", &n, &t, &a);
	// Read the heights as a slice of float64
	double *heights = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		fscanf(in, "%lf", &heights[i]);
	}

	// Initialize minimum difference and index for tracking the closest height
	double minDiff = AbsDiffFloat64(t - heights[0] * 0.006, a);
	int minIdx = 0;

	// Iterate through the heights to find the one with the minimum temperature difference
	for (int i = 0; i < n; i++) {
		double diff = AbsDiffFloat64(t - heights[i] * 0.006, a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i; // Update the index of the closest height
		}
	}

	// Output the 1-based index of the closest height
	fprintf(out, "%d\n", minIdx + 1);

	// Free memory
	free(heights);
	fclose(in);
	fclose(out);
	return 0;
}

// AbsDiffFloat64 calculates the absolute difference between two float64 numbers
double AbsDiffFloat64(double n1, double n2) {
	return fabs(n1 - n2);
}

The C code compiles and runs successfully.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
double AbsDiffFloat64(double n1, double n2);

// Main function
int main(void) {
	// Initialize input/output handling
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	if (in == NULL || out == NULL) {
		perror("An error occurred opening the file");
		exit(EXIT_FAILURE);
	}

	// Read the number of heights, target temperature, and actual temperature
	int n, t, a;
	fscanf(in, "%d %lf %lf", &n, &t, &a);
	// Read the heights as a slice of float64
	double *heights = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		fscanf(in, "%lf", &heights[i]);
	}

	// Initialize minimum difference and index for tracking the closest height
	double minDiff = AbsDiffFloat64(t - heights[0] * 0.006, a);
	int minIdx = 0;

	// Iterate through the heights to find the one with the minimum temperature difference
	for (int i = 0; i < n; i++) {
		double diff = AbsDiffFloat64(t - heights[i] * 0.006, a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i; // Update the index of the closest height
		}
	}

	// Output the 1-based index of the closest height
	fprintf(out, "%d\n", minIdx + 1);

	// Free memory
	free(heights);
	fclose(in);
	fclose(out);
	return 0;
}

// AbsDiffFloat64 calculates the absolute difference between two float64 numbers
double AbsDiffFloat64(double n1, double n2) {
	return fabs(n1 - n2);
}

The C code compiles and runs successfully.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
double AbsDiffFloat64(double n1, double n2);

// Main function
int main(void) {
	// Initialize input/output handling
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	if (in == NULL || out == NULL) {
		perror("An error occurred opening the file");
		exit(EXIT_FAILURE);
	}

	// Read the number of heights, target temperature, and actual temperature
	int n, t, a;
	fscanf(in, "%d %lf %lf", &n, &t, &a);
	// Read the heights as a slice of float64
	double *heights = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		fscanf(in, "%lf", &heights[i]);
	}

	// Initialize minimum difference and index for tracking the closest height
	double minDiff = AbsDiffFloat64(t - heights[0] * 0.006, a);
	int minIdx = 0;

	// Iterate through the heights to find the one with the minimum temperature difference
	for (int i = 0; i < n; i++) {
		double diff = AbsDiffFloat64(t - heights[i] * 0.006, a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i; // Update the index of the closest height
		}
	}

	// Output the 1-based index of the closest height
	fprintf(out, "%d\n", minIdx + 1);

	// Free memory
	free(heights);
	fclose(in);
	fclose(out);
	return 0;
}

// AbsDiffFloat64 calculates the absolute difference between two float64 numbers
double AbsDiffFloat64(double n1, double n2) {
	return fabs(n1 - n2);
}

The C code compiles and runs successfully.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
double AbsDiffFloat64(double n1, double n2);

// Main function
int main(void) {
	// Initialize input/output handling
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	if (in == NULL || out == NULL) {
		perror("An error occurred opening the file");
		exit(EXIT_FAILURE);
	}

	// Read the number of heights, target temperature, and actual temperature
	int n, t, a;
	fscanf(in, "%d %lf %lf", &n, &t, &a);
	// Read the heights as a slice of float64
	double *heights = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		fscanf(in, "%lf", &heights[i]);
	}

	// Initialize minimum difference and index for tracking the closest height
	double minDiff = AbsDiffFloat64(t - heights[0] * 0.006, a);
	int minIdx = 0;

	// Iterate through the heights to find the one with the minimum temperature difference
	for (int i = 0; i < n; i++) {
		double diff = AbsDiffFloat64(t - heights[i] * 0.006, a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i; // Update the index of the closest height
		}
	}

	// Output the 1-based index of the closest height
	fprintf(out, "%d\n", minIdx + 1);

	// Free memory
	free(heights);
	fclose(in);
	fclose(out);
	return 0;
}

// AbsDiffFloat64 calculates the absolute difference between two float64 numbers
double AbsDiffFloat64(double n1, double n2) {
	return fabs(n1 - n2);
}

The C code compiles and runs successfully.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
double AbsDiffFloat64(double n1, double n2);

// Main function
int main(void) {
	// Initialize input/output handling
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	if (in == NULL || out == NULL) {
		perror("An error occurred opening the file");
		exit(EXIT_FAILURE);
	}

	// Read the number of heights, target temperature, and actual temperature
	int n, t, a;
	fscanf(in, "%d %lf %lf", &n, &t, &a);
	// Read the heights as a slice of float64
	double *heights = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		fscanf(in, "%lf", &heights[i]);
	}

	// Initialize minimum difference and index for tracking the closest height
	double minDiff = AbsDiffFloat64(t - heights[0] * 0.006, a);
	int minIdx = 0;

	// Iterate through the heights to find the one with the minimum temperature difference
	for (int i = 0; i < n; i++) {
		double diff = AbsDiffFloat64(t - heights[i] * 0.006, a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i; // Update the index of the closest height
		}
	}

	// Output the 1-based index of the closest height
	fprintf(out, "%d\n", minIdx + 1);

	// Free memory
	free(heights);
	fclose(in);
	fclose(out);
	return 0;
}

// AbsDiffFloat64 calculates the absolute difference between two float64 numbers
double AbsDiffFloat64(double n1, double n2) {
	return fabs(n1 - n2);
}

The C code compiles and runs successfully.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
double AbsDiffFloat64(double n1, double n2);

// Main function
int main(void) {
	// Initialize input/output handling
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	if (in == NULL || out == NULL) {
		perror("An error occurred opening the file");
		exit(EXIT_FAILURE);
	}

	// Read the number of heights, target temperature, and actual temperature
	int n, t, a;
	fscanf(in, "%d %lf %lf", &n, &t, &a);
	// Read the heights as a slice of float64
	double *heights = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		fscanf(in, "%lf", &heights[i]);
	}

	// Initialize minimum difference and index for tracking the closest height
	double minDiff = AbsDiffFloat64(t - heights[0] * 0.006, a);
	int minIdx = 0;

	// Iterate through the heights to find the one with the minimum temperature difference
	for (int i = 0; i < n; i++) {
		double diff = AbsDiffFloat64(t - heights[i] * 0.006, a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i; // Update the index of the closest height
		}
	}

	// Output the 1-based index of the closest height
	fprintf(out, "%d\n", minIdx + 1);

	// Free memory
	free(heights);
	fclose(in);
	fclose(out);
	return 0;
}

// AbsDiffFloat64 calculates the absolute difference between two float64 numbers
double AbsDiffFloat64(double n1, double n2) {
	return fabs(n1 - n2);
}

The C code compiles and runs successfully.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
double AbsDiffFloat64(double n1, double n2);

// Main function
int main(void) {
	// Initialize input/output handling
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	if (in == NULL || out == NULL) {
		perror("An error occurred opening the file");
		exit(EXIT_FAILURE);
	}

	// Read the number of heights, target temperature, and actual temperature
	int n, t, a;
	fscanf(in, "%d %lf %lf", &n, &t, &a);
	// Read the heights as a slice of float64
	double *heights = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		fscanf(in, "%lf", &heights[i]);
	}

	// Initialize minimum difference and index for tracking the closest height
	double minDiff = AbsDiffFloat64(t - heights[0] * 0.006, a);
	int minIdx = 0;

	// Iterate through the heights to find the one with the minimum temperature difference
	for (int i = 0; i < n; i++) {
		double diff = AbsDiffFloat64(t - heights[i] * 0.006, a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i; // Update the index of the closest height
		}
	}

	// Output the 1-based index of the clos