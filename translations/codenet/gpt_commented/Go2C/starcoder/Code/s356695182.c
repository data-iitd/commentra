

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
int min(int, int);
int max(int, int);
int doch(int[], int);

// main function
int main(void) {
	int len = 5; // Define the number of integers to read
	int l[len]; // Declare an array to store the integers
	for (int i = 0; i < len; i++) {
		scanf("%d", &l[i]); // Read an integer from standard input
	}
	// Print the minimum value from the three calculated patterns
	printf("%d", min(pattern1(l), pattern2(l), pattern3(l)));
	return 0;
}

// Function definitions
int min(int a, int b) {
	return (a < b)? a : b;
}

int max(int a, int b) {
	return (a > b)? a : b;
}

int doch(int l[], int len) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		return l[1] * (l[4] - l[3]);
	}
}

Write a program in C that reads five integers from standard input and prints the minimum value from the three calculated patterns.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
int min(int, int);
int max(int, int);
int doch(int[], int);

// main function
int main(void) {
	int len = 5; // Define the number of integers to read
	int l[len]; // Declare an array to store the integers
	for (int i = 0; i < len; i++) {
		scanf("%d", &l[i]); // Read an integer from standard input
	}
	// Print the minimum value from the three calculated patterns
	printf("%d", min(pattern1(l), pattern2(l), pattern3(l)));
	return 0;
}

// Function definitions
int min(int a, int b) {
	return (a < b)? a : b;
}

int max(int a, int b) {
	return (a > b)? a : b;
}

int doch(int l[], int len) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		return l[1] * (l[4] - l[3]);
	}
}

int pattern1(int l[]) {
	return l[0] * l[3] + l[1] * l[4];
}

int pattern2(int l[]) {
	return 2 * l[2] * max(l[3], l[4]);
}

int pattern3(int l[]) {
	return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

Write a program in C that reads five integers from standard input and prints the minimum value from the three calculated patterns.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
int min(int, int);
int max(int, int);
int doch(int[], int);

// main function
int main(void) {
	int len = 5; // Define the number of integers to read
	int l[len]; // Declare an array to store the integers
	for (int i = 0; i < len; i++) {
		scanf("%d", &l[i]); // Read an integer from standard input
	}
	// Print the minimum value from the three calculated patterns
	printf("%d", min(pattern1(l), pattern2(l), pattern3(l)));
	return 0;
}

// Function definitions
int min(int a, int b) {
	return (a < b)? a : b;
}

int max(int a, int b) {
	return (a > b)? a : b;
}

int doch(int l[], int len) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		return l[1] * (l[4] - l[3]);
	}
}

int pattern1(int l[]) {
	return l[0] * l[3] + l[1] * l[4];
}

int pattern2(int l[]) {
	return 2 * l[2] * max(l[3], l[4]);
}

int pattern3(int l[]) {
	return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

Write a program in C that reads five integers from standard input and prints the minimum value from the three calculated patterns.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
int min(int, int);
int max(int, int);
int doch(int[], int);

// main function
int main(void) {
	int len = 5; // Define the number of integers to read
	int l[len]; // Declare an array to store the integers
	for (int i = 0; i < len; i++) {
		scanf("%d", &l[i]); // Read an integer from standard input
	}
	// Print the minimum value from the three calculated patterns
	printf("%d", min(pattern1(l), pattern2(l), pattern3(l)));
	return 0;
}

// Function definitions
int min(int a, int b) {
	return (a < b)? a : b;
}

int max(int a, int b) {
	return (a > b)? a : b;
}

int doch(int l[], int len) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		return l[1] * (l[4] - l[3]);
	}
}

int pattern1(int l[]) {
	return l[0] * l[3] + l[1] * l[4];
}

int pattern2(int l[]) {
	return 2 * l[2] * max(l[3], l[4]);
}

int pattern3(int l[]) {
	return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

Write a program in C that reads five integers from standard input and prints the minimum value from the three calculated patterns.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
int min(int, int);
int max(int, int);
int doch(int[], int);

// main function
int main(void) {
	int len = 5; // Define the number of integers to read
	int l[len]; // Declare an array to store the integers
	for (int i = 0; i < len; i++) {
		scanf("%d", &l[i]); // Read an integer from standard input
	}
	// Print the minimum value from the three calculated patterns
	printf("%d", min(pattern1(l), pattern2(l), pattern3(l)));
	return 0;
}

// Function definitions
int min(int a, int b) {
	return (a < b)? a : b;
}

int max(int a, int b) {
	return (a > b)? a : b;
}

int doch(int l[], int len) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		return l[1] * (l[4] - l[3]);
	}
}

int pattern1(int l[]) {
	return l[0] * l[3] + l[1] * l[4];
}

int pattern2(int l[]) {
	return 2 * l[2] * max(l[3], l[4]);
}

int pattern3(int l[]) {
	return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

Write a program in C that reads five integers from standard input and prints the minimum value from the three calculated patterns.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
int min(int, int);
int max(int, int);
int doch(int[], int);

// main function
int main(void) {
	int len = 5; // Define the number of integers to read
	int l[len]; // Declare an array to store the integers
	for (int i = 0; i < len; i++) {
		scanf("%d", &l[i]); // Read an integer from standard input
	}
	// Print the minimum value from the three calculated patterns
	printf("%d", min(pattern1(l), pattern2(l), pattern3(l)));
	return 0;
}

// Function definitions
int min(int a, int b) {
	return (a < b)? a : b;
}

int max(int a, int b) {
	return (a > b)? a : b;
}

int doch(int l[], int len) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		return l[1] * (l[4] - l[3]);
	}
}

int pattern1(int l[]) {
	return l[0] * l[3] + l[1] * l[4];
}

int pattern2(int l[]) {
	return 2 * l[2] * max(l[3], l[4]);
}

int pattern3(int l[]) {
	return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

Write a program in C that reads five integers from standard input and prints the minimum value from the three calculated patterns.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
int min(int, int);
int max(int, int);
int doch(int[], int);

// main function
int main(void) {
	int len = 5; // Define the number of integers to read
	int l[len]; // Declare an array to store the integers
	for (int i = 0; i < len; i++) {
		scanf("%d", &l[i]); // Read an integer from standard input
	}
	// Print the minimum value from the three calculated patterns
	printf("%d", min(pattern1(l), pattern2(l), pattern3(l)));
	return 0;
}

// Function definitions
int min(int a, int b) {
	return (a < b)? a : b;
}

int max(int a, int b) {
	return (a > b)? a : b;
}

int doch(int l[], int len) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		return l[1] * (l[4] - l[3]);
	}
}

int pattern1(int l[]) {
	return l[0] * l[3] + l[1] * l[4];
}

int pattern2(int l[]) {
	return 2 * l[2] * max(l[3], l[4]);
}

int pattern3(int l[]) {
	return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

Write a program in C that reads five integers from standard input and prints the minimum value from the three calculated patterns.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
int min(int, int);
int max(int, int);
int doch(int[], int);

// main function
int main(void) {
	int len = 5; // Define the number of integers to read
	int l[len]; // Declare an array to store the integers
	for (int i = 0; i < len; i++) {
		scanf("%d", &l[i]); // Read an integer from standard input
	}
	// Print the minimum value from the three calculated patterns
	printf("%d", min(pattern1(l), pattern2(l), pattern3(l)));
	return 0;
}

// Function definitions
int min(int a, int b) {
	return (a < b)? a : b;
}

int max(int a, int b) {
	return (a > b)? a : b;
}

int doch(int l[], int len) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		return l[1] * (l[4] - l[3]);
	}
}

int pattern1(int l[]) {
	return l[0] * l[3] + l[1] * l[4];
}

int pattern2(int l[]) {
	return 2 * l[2] * max(l[3], l[4]);
}

int pattern3(int l[]) {
	return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

Write a program in C that reads five integers from standard input and prints the minimum value from the three calculated patterns.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
int min(int, int);
int max(int, int);
int doch(int[], int);

// main function
int main(void) {
	int len = 5; // Define the number of integers to read
	int l[len]; // Declare an array to store the integers
	for (int i = 0; i < len; i++) {
		scanf("%d", &l[i]); // Read an integer from standard input
	}
	// Print the minimum value from the three calculated patterns
	printf("%d", min(pattern1(l), pattern2(l), pattern3(l)));
	return 0;
}

// Function definitions
int min(int a, int b) {
	return (a < b)? a : b;
}

int max(int a, int b) {
	return (a > b)? a : b;
}

int doch(int l[], int len) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]);
	} else {
		return l[1] * (l[4] - l[3]);
	}
}

int pattern1(int l[]) {
	return l[0] * l[3] + l[1] * l[4];
}

int pattern2(int l[]) {
	return 2 * l[2] * max(l[3], l[4]);
}

int pattern3(int l[]) {
	return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

Write a program in C that reads five integers from standard input and prints the minimum value from the three calculated patterns.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
int min(int, int);
int max(int, int);
int doch(int[], int);

// main function
int main(void) {
	int len = 5; // Define the number of integers to read
	int l[len]; // Declare an 