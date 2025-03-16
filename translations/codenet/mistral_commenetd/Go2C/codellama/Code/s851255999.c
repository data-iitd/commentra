#include <stdio.h>
#include <stdlib.h>

// Define a structure named "work" with two fields: "time" and "limit" of type int
typedef struct {
	int time;
	int limit;
} work;

// Define a function named "compare" that takes two "work" structures as arguments and returns an int
int compare(work w1, work w2) {
	// Check if the limit of the first work structure is less than the limit of the second work structure
	if (w1.limit < w2.limit) {
		// If it is, return -1
		return -1;
	}

	// Check if the limit of the first work structure is greater than the limit of the second work structure
	if (w1.limit > w2.limit) {
		// If it is, return 1
		return 1;
	}

	// If the limits of the two work structures are equal, return 0
	return 0;
}

// Define a function named "sort" that takes a pointer to an array of "work" structures and the length of the array as arguments
void sort(work *ws, int n) {
	// Declare a variable named "i" of type int and set its value to 0
	int i = 0;

	// Declare a variable named "j" of type int and set its value to 0
	int j = 0;

	// Declare a variable named "temp" of type "work" and set its value to the first work structure in the array
	work temp = ws[0];

	// Iterate through the array of work structures
	for (i = 0; i < n; i++) {
		// Iterate through the array of work structures
		for (j = 0; j < n; j++) {
			// Check if the limit of the current work structure is less than the limit of the next work structure
			if (ws[j].limit < ws[j + 1].limit) {
				// If it is, swap the current work structure with the next work structure
				temp = ws[j];
				ws[j] = ws[j + 1];
				ws[j + 1] = temp;
			}
		}
	}
}

// Define a function named "main" that takes no arguments
int main() {
	// Declare a variable named "n" of type int and initialize it with the value of the first input
	int n = 0;
	scanf("%d", &n);

	// Declare a variable named "ws" of type "work" and initialize it with the value of the second input
	work ws[n];
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ws[i].time, &ws[i].limit);
	}

	// Call the "sort" function with the "ws" array and the "n" variable as arguments
	sort(ws, n);

	// Declare a variable named "sum" of type int64 and set its value to 0
	int64_t sum = 0;

	// Iterate through the sorted "ws" array
	for (int i = 0; i < n; i++) {
		// Add the time of the current work structure to the "sum" variable
		sum += ws[i].time;

		// Check if the sum is greater than the limit of the current work structure
		if (sum > ws[i].limit) {
			// If it is, print "No" and return from the function
			printf("No\n");
			return 0;
		}
	}

	// If the loop completes without finding a work structure whose time exceeds its limit, print "Yes"
	printf("Yes\n");

	// Return 0 from the function
	return 0;
}

