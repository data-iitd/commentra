

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for large inputs.
char* get_next_string(FILE* fp) {
	static char* buffer = NULL;
	static size_t buffer_size = 0;
	if (buffer == NULL) {
		buffer_size = 1024;
		buffer = malloc(buffer_size);
	}
	char* token = NULL;
	if (fgets(buffer, buffer_size, fp) == NULL) {
		return NULL;
	}
	token = strtok(buffer, " ");
	return token;
}

// get_next_int converts the next string from the scanner to an integer.
int get_next_int(FILE* fp) {
	char* token = get_next_string(fp);
	int value = atoi(token);
	return value;
}

int main(int argc, char* argv[]) {
	// Determine the input source: standard input or a file specified as a command-line argument.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Initialize the scanner for reading input.
	char* token = get_next_string(fp);

	// Create a buffered writer for output.
	FILE* writer = stdout;

	// Read the number of elements from the input.
	int n = atoi(token);

	// Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
	int* aa = malloc(sizeof(int) * (n + 2));
	int sum = 0;

	// Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
	for (int i = 0; i < n; i++) {
		token = get_next_string(fp);
		aa[i + 1] = atoi(token);
		sum += abs(aa[i + 1] - aa[i]);
	}
	// Include the difference between the last element and the element before it.
	sum += abs(aa[n + 1] - aa[n]);

	// Calculate and print the result for each element.
	for (int i = 1; i < n + 1; i++) {
		// Calculate the new sum of absolute differences if the i-th element is removed.
		int ans = sum - abs(aa[i + 1] - aa[i]) - abs(aa[i] - aa[i - 1]) + abs(aa[i + 1] - aa[i - 1]);
		fprintf(writer, "%d\n", ans); // Output the result for the current element.
	}

	// Flush the buffered writer to ensure all output is written.
	fflush(writer);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for large inputs.
char* get_next_string(FILE* fp) {
	static char* buffer = NULL;
	static size_t buffer_size = 0;
	if (buffer == NULL) {
		buffer_size = 1024;
		buffer = malloc(buffer_size);
	}
	char* token = NULL;
	if (fgets(buffer, buffer_size, fp) == NULL) {
		return NULL;
	}
	token = strtok(buffer, " ");
	return token;
}

// get_next_int converts the next string from the scanner to an integer.
int get_next_int(FILE* fp) {
	char* token = get_next_string(fp);
	int value = atoi(token);
	return value;
}

int main(int argc, char* argv[]) {
	// Determine the input source: standard input or a file specified as a command-line argument.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Initialize the scanner for reading input.
	char* token = get_next_string(fp);

	// Create a buffered writer for output.
	FILE* writer = stdout;

	// Read the number of elements from the input.
	int n = atoi(token);

	// Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
	int* aa = malloc(sizeof(int) * (n + 2));
	int sum = 0;

	// Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
	for (int i = 0; i < n; i++) {
		token = get_next_string(fp);
		aa[i + 1] = atoi(token);
		sum += abs(aa[i + 1] - aa[i]);
	}
	// Include the difference between the last element and the element before it.
	sum += abs(aa[n + 1] - aa[n]);

	// Calculate and print the result for each element.
	for (int i = 1; i < n + 1; i++) {
		// Calculate the new sum of absolute differences if the i-th element is removed.
		int ans = sum - abs(aa[i + 1] - aa[i]) - abs(aa[i] - aa[i - 1]) + abs(aa[i + 1] - aa[i - 1]);
		fprintf(writer, "%d\n", ans); // Output the result for the current element.
	}

	// Flush the buffered writer to ensure all output is written.
	fflush(writer);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for large inputs.
char* get_next_string(FILE* fp) {
	static char* buffer = NULL;
	static size_t buffer_size = 0;
	if (buffer == NULL) {
		buffer_size = 1024;
		buffer = malloc(buffer_size);
	}
	char* token = NULL;
	if (fgets(buffer, buffer_size, fp) == NULL) {
		return NULL;
	}
	token = strtok(buffer, " ");
	return token;
}

// get_next_int converts the next string from the scanner to an integer.
int get_next_int(FILE* fp) {
	char* token = get_next_string(fp);
	int value = atoi(token);
	return value;
}

int main(int argc, char* argv[]) {
	// Determine the input source: standard input or a file specified as a command-line argument.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Initialize the scanner for reading input.
	char* token = get_next_string(fp);

	// Create a buffered writer for output.
	FILE* writer = stdout;

	// Read the number of elements from the input.
	int n = atoi(token);

	// Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
	int* aa = malloc(sizeof(int) * (n + 2));
	int sum = 0;

	// Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
	for (int i = 0; i < n; i++) {
		token = get_next_string(fp);
		aa[i + 1] = atoi(token);
		sum += abs(aa[i + 1] - aa[i]);
	}
	// Include the difference between the last element and the element before it.
	sum += abs(aa[n + 1] - aa[n]);

	// Calculate and print the result for each element.
	for (int i = 1; i < n + 1; i++) {
		// Calculate the new sum of absolute differences if the i-th element is removed.
		int ans = sum - abs(aa[i + 1] - aa[i]) - abs(aa[i] - aa[i - 1]) + abs(aa[i + 1] - aa[i - 1]);
		fprintf(writer, "%d\n", ans); // Output the result for the current element.
	}

	// Flush the buffered writer to ensure all output is written.
	fflush(writer);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for large inputs.
char* get_next_string(FILE* fp) {
	static char* buffer = NULL;
	static size_t buffer_size = 0;
	if (buffer == NULL) {
		buffer_size = 1024;
		buffer = malloc(buffer_size);
	}
	char* token = NULL;
	if (fgets(buffer, buffer_size, fp) == NULL) {
		return NULL;
	}
	token = strtok(buffer, " ");
	return token;
}

// get_next_int converts the next string from the scanner to an integer.
int get_next_int(FILE* fp) {
	char* token = get_next_string(fp);
	int value = atoi(token);
	return value;
}

int main(int argc, char* argv[]) {
	// Determine the input source: standard input or a file specified as a command-line argument.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Initialize the scanner for reading input.
	char* token = get_next_string(fp);

	// Create a buffered writer for output.
	FILE* writer = stdout;

	// Read the number of elements from the input.
	int n = atoi(token);

	// Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
	int* aa = malloc(sizeof(int) * (n + 2));
	int sum = 0;

	// Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
	for (int i = 0; i < n; i++) {
		token = get_next_string(fp);
		aa[i + 1] = atoi(token);
		sum += abs(aa[i + 1] - aa[i]);
	}
	// Include the difference between the last element and the element before it.
	sum += abs(aa[n + 1] - aa[n]);

	// Calculate and print the result for each element.
	for (int i = 1; i < n + 1; i++) {
		// Calculate the new sum of absolute differences if the i-th element is removed.
		int ans = sum - abs(aa[i + 1] - aa[i]) - abs(aa[i] - aa[i - 1]) + abs(aa[i + 1] - aa[i - 1]);
		fprintf(writer, "%d\n", ans); // Output the result for the current element.
	}

	// Flush the buffered writer to ensure all output is written.
	fflush(writer);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for large inputs.
char* get_next_string(FILE* fp) {
	static char* buffer = NULL;
	static size_t buffer_size = 0;
	if (buffer == NULL) {
		buffer_size = 1024;
		buffer = malloc(buffer_size);
	}
	char* token = NULL;
	if (fgets(buffer, buffer_size, fp) == NULL) {
		return NULL;
	}
	token = strtok(buffer, " ");
	return token;
}

// get_next_int converts the next string from the scanner to an integer.
int get_next_int(FILE* fp) {
	char* token = get_next_string(fp);
	int value = atoi(token);
	return value;
}

int main(int argc, char* argv[]) {
	// Determine the input source: standard input or a file specified as a command-line argument.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Initialize the scanner for reading input.
	char* token = get_next_string(fp);

	// Create a buffered writer for output.
	FILE* writer = stdout;

	// Read the number of elements from the input.
	int n = atoi(token);

	// Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
	int* aa = malloc(sizeof(int) * (n + 2));
	int sum = 0;

	// Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
	for (int i = 0; i < n; i++) {
		token = get_next_string(fp);
		aa[i + 1] = atoi(token);
		sum += abs(aa[i + 1] - aa[i]);
	}
	//