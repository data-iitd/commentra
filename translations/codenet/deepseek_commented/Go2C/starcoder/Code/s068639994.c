#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Helper functions to find the minimum and maximum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// main function to initialize the program.
int main() {
	// Get the number of elements in the slice.
	int n = getInt();
	// Get the slice of integers.
	int *ls = getIntSlice(n);
	// Create a reversed version of the slice.
	int *lsRev = malloc(n * sizeof(int));
	memcpy(lsRev, ls, n * sizeof(int));
	// Sort the original slice in ascending order.
	qsort(ls, n, sizeof(int), compare);
	// Sort the reversed slice in descending order.
	qsort(lsRev, n, sizeof(int), compareReverse);

	// Initialize the answer variable.
	int ans = 0;
	// Loop through the slice to calculate the answer.
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// Calculate p and q based on the current elements.
			int p = min(ls[i], ls[j]);
			int q = max(ls[i], ls[j]);
			// Calculate x and y based on p and q.
			int x = q - p;
			int y = q + p;

			// Find the left boundary using binary search.
			int l = binarySearch(ls, n, x, true);
			// Find the right boundary using binary search.
			int r = n - binarySearch(lsRev, n, y, false);

			// Calculate the sum of valid pairs.
			int sum = r - l;
			// Adjust the sum if the current indices are within the range.
			if (i >= l) && (i <= r) {
				sum--;
			}
			if (j >= l) && (j <= r) {
				sum--;
			}
			// Ensure the sum is not negative.
			sum = max(0, sum);
			// Add the sum to the answer.
			ans += sum;
		}
	}

	// Divide the answer by 3 to get the final result.
	ans /= 3;
	// Print the final answer.
	puts(ans);
}

// Helper function to compare two integers.
int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

// Helper function to compare two integers in reverse order.
int compareReverse(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

// Helper function to perform binary search.
int binarySearch(int *arr, int n, int x, bool isAscending) {
	int l = 0;
	int r = n - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (arr[m] == x) {
			return m;
		}
		if (isAscending) {
			if (arr[m] < x) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		} else {
			if (arr[m] > x) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
	}
	return l;
}

// Helper functions to find the minimum and maximum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// -----------------------------------------

// Global variables for input/output operations.
int *inputBuffer = NULL;
int inputBufferSize = 0;
int inputBufferPos = 0;

// Global variables for input/output operations.
int *outputBuffer = NULL;
int outputBufferSize = 0;
int outputBufferPos = 0;

// Helper function to get an integer from the input buffer.
int getInt() {
	// If the input buffer has been exhausted, read the next line from the standard input.
	if (inputBufferPos >= inputBufferSize) {
		if (inputBuffer) {
			free(inputBuffer);
		}
		inputBuffer = NULL;
		inputBufferSize = 0;
		inputBufferPos = 0;
		char *inputLine = NULL;
		size_t inputLineSize = 0;
		getline(&inputLine, &inputLineSize, stdin);
		inputBufferSize = inputLineSize + 1;
		inputBuffer = malloc(inputBufferSize);
		assert(inputBuffer);
		memcpy(inputBuffer, inputLine, inputLineSize);
		free(inputLine);
		inputBuffer[inputLineSize] = 0;
	}
	// Read the next integer from the input buffer.
	int val = 0;
	int neg = 1;
	int i = inputBufferPos;
	if (inputBuffer[i] == '-') {
		neg = -1;
		i++;
	}
	for (i = i; i < inputBufferSize && inputBuffer[i] >= '0' && inputBuffer[i] <= '9'; i++) {
		val = val * 10 + (inputBuffer[i] - '0');
	}
	inputBufferPos = i + 1;
	return val * neg;
}

// Helper function to get a slice of integers from the input buffer.
int *getIntSlice(int n) {
	int *arr = malloc(n * sizeof(int));
	assert(arr);
	for (int i = 0; i < n; i++) {
		arr[i] = getInt();
	}
	return arr;
}

// Helper function to get a string from the input buffer.
char *getString() {
	// If the input buffer has been exhausted, read the next line from the standard input.
	if (inputBufferPos >= inputBufferSize) {
		if (inputBuffer) {
			free(inputBuffer);
		}
		inputBuffer = NULL;
		inputBufferSize = 0;
		inputBufferPos = 0;
		char *inputLine = NULL;
		size_t inputLineSize = 0;
		getline(&inputLine, &inputLineSize, stdin);
		inputBufferSize = inputLineSize + 1;
		inputBuffer = malloc(inputBufferSize);
		assert(inputBuffer);
		memcpy(inputBuffer, inputLine, inputLineSize);
		free(inputLine);
		inputBuffer[inputLineSize] = 0;
	}
	// Read the next string from the input buffer.
	char *val = malloc(inputBufferSize - inputBufferPos + 1);
	assert(val);
	int i = inputBufferPos;
	int j = 0;
	for (i = inputBufferPos; i < inputBufferSize && inputBuffer[i]!= 0; i++) {
		val[j++] = inputBuffer[i];
	}
	val[j] = 0;
	inputBufferPos = i + 1;
	return val;
}

// Helper function to write a string to the output buffer.
void putString(char *s) {
	// If the output buffer has been exhausted, write the output buffer to the standard output.
	if (outputBufferPos >= outputBufferSize) {
		if (outputBuffer) {
			fwrite(outputBuffer, 1, outputBufferPos, stdout);
			free(outputBuffer);
		}
		outputBuffer = NULL;
		outputBufferSize = 0;
		outputBufferPos = 0;
	}
	// Write the string to the output buffer.
	int len = strlen(s);
	if (outputBufferPos + len >= outputBufferSize) {
		outputBufferSize = outputBufferPos + len + 1;
		outputBuffer = realloc(outputBuffer, outputBufferSize);
		assert(outputBuffer);
	}
	memcpy(outputBuffer + outputBufferPos, s, len);
	outputBufferPos += len;
	outputBuffer[outputBufferPos] = 0;
}

// Helper function to write an integer to the output buffer.
void putInt(int val) {
	// If the output buffer has been exhausted, write the output buffer to the standard output.
	if (outputBufferPos >= outputBufferSize) {
		if (outputBuffer) {
			fwrite(outputBuffer, 1, outputBufferPos, stdout);
			free(outputBuffer);
		}
		outputBuffer = NULL;
		outputBufferSize = 0;
		outputBufferPos = 0;
	}
	// Write the integer to the output buffer.
	if (val < 0) {
		outputBuffer[outputBufferPos++] = '-';
		val = -val;
	}
	int i = 0;
	int j = 0;
	int n = 0;
	while (val > 0) {
		n = val % 10;
		val /= 10;
		outputBuffer[outputBufferPos++] = '0' + n;
	}
	outputBuffer[outputBufferPos] = 0;
	for (i = 0; i < outputBufferPos / 2; i++) {
		j = outputBufferPos - 1 - i;
		char tmp = outputBuffer[i];
		outputBuffer[i] = outputBuffer[j];
		outputBuffer[j] = tmp;
	}
}

// Helper function to write a slice of integers to the output buffer.
void putIntSlice(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		putInt(arr[i]);
		if (i < n - 1) {
			putString(" ");
		}
	}
}

// Helper function to write a newline to the output buffer.
void putNewline() {
	putString("\n");
}

// Helper function to write the output buffer to the standard output.
void flush() {
	if (outputBufferPos > 0) {
		fwrite(outputBuffer, 1, outputBufferPos, stdout);
		outputBufferPos = 0;
	}
}

// Helper function to write the output buffer to the standard output.
void flush() {
	if (outputBufferPos > 0) {
		fwrite(outputBuffer, 1, outputBufferPos, stdout);
		outputBufferPos = 0;
	}
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(int val) {
	putInt(val);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(int *arr, int n) {
	putIntSlice(arr, n);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(s);
	putNewline();
}

// Helper function to write the output buffer to the standard output.
void puts(char *s) {
	putString(