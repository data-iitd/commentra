#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Run function reads input from the reader, processes it, and writes the output to the writer.
void Run(FILE* r, FILE* w) {
	// Read the first line which contains two integers N and D.
	int N, D;
	fscanf(r, "%d %d\n", &N, &D);

	// Read the next N lines which contain pairs of integers representing points.
	int lines[N][2];
	for (int i = 0; i < N; i++) {
		fscanf(r, "%d %d\n", &lines[i][0], &lines[i][1]);
	}

	// Initialize a counter to keep track of points within the given distance.
	int count = 0;

	// Iterate over each point and calculate the distance from the origin.
	for (int i = 0; i < N; i++) {
		// Calculate the Euclidean distance of the point from the origin.
		double d = sqrt(lines[i][0] * lines[i][0] + lines[i][1] * lines[i][1]);
		// Check if the distance is within the given limit.
		if (D >= d) {
			count++;
		}
	}

	// Write the count of points within the distance to the writer.
	fprintf(w, "%d\n", count);
}

// main function initializes the Run function with stdin and stdout.
int main() {
	Run(stdin, stdout);
}

