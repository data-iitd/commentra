#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// N: [1, 2e5]
// len(S) = N
// P: [2, 10000], prime
int main() {
	// Initialize the input scanner with a buffer size of 256 KB
	inputScanner *sc = newInputScanner(true, 256);
	
	// Read the integer values N and P, and the string S from input
	int N = sc->nextInt();
	int P = sc->nextInt();
	char *S = sc->nextStr();
	
	// Check the sub-numbers based on the conditions and print the result
	int answer = checkSubNumbers(N, P, S);
	printf("%d\n", answer);
	
	// Free the memory allocated for the input scanner
	free(sc);
	
	return 0;
}

// checkSubNumbers determines the method to check sub-numbers based on the value of P
int checkSubNumbers(int N, int P, char *S) {
	int answer = 0;
	int n;
	
	// Iterate through the string S from the end to the beginning
	for (int i = N - 1; i >= 0; i--) {
		// Convert the character to an integer
		n = S[i] - '0';
		
		// Check if the digit is divisible by P and update the answer
		if (n % P == 0) {
			answer += i + 1; // Count the number of valid sub-numbers
		}
	}
	return answer;
}

// inputScanner wraps bufio.Scanner for easier input handling
typedef struct {
	char *buffer;
	int bufferSize;
	int bufferIndex;
	int bufferEnd;
	int scanWords;
} inputScanner;

// newInputScanner initializes a new input scanner with a specified buffer size
inputScanner *newInputScanner(bool scanWords, int sizeInKB) {
	inputScanner *sc = (inputScanner *)malloc(sizeof(inputScanner));
	sc->bufferSize = sizeInKB * 1024; // Calculate the buffer capacity in bytes
	sc->buffer = (char *)malloc(sc->bufferSize); // Create a buffer of the specified size
	sc->bufferIndex = 0; // Initialize the buffer index
	sc->bufferEnd = 0; // Initialize the buffer end index
	sc->scanWords = scanWords; // Set the scanner to split input by words
	return sc;
}

// nextInt reads the next integer from input
int inputScanner_nextInt(inputScanner *sc) {
	char *str = inputScanner_nextStr(sc); // Convert the next string to an integer
	int i = atoi(str);
	free(str); // Free the memory allocated for the string
	return i;
}

// nextUInt64 reads the next uint64 from input
uint64_t inputScanner_nextUInt64(inputScanner *sc) {
	char *str = inputScanner_nextStr(sc); // Convert the next string to uint64
	uint64_t i = strtoull(str, NULL, 10);
	free(str); // Free the memory allocated for the string
	return i;
}

// nextStr reads the next string from input
char *inputScanner_nextStr(inputScanner *sc) {
	if (sc->bufferIndex == sc->bufferEnd) { // If the buffer is empty
		sc->bufferIndex = 0; // Reset the buffer index
		sc->bufferEnd = fread(sc->buffer, 1, sc->bufferSize, stdin); // Read the next input
		if (sc->bufferEnd == 0) { // If there is no more input
			return NULL; // Return NULL
		}
	}
	
	// If the scanner is set to split input by words
	if (sc->scanWords) {
		// Find the next word in the buffer
		int startIndex = sc->bufferIndex;
		while (sc->buffer[sc->bufferIndex] != ' ' && sc->bufferIndex < sc->bufferEnd) {
			sc->bufferIndex++;
		}
		
		// Allocate memory for the word
		int length = sc->bufferIndex - startIndex;
		char *word = (char *)malloc(length + 1);
		
		// Copy the word from the buffer to the allocated memory
		memcpy(word, sc->buffer + startIndex, length);
		word[length] = '\0'; // Add the null terminator
		
		// Skip the space character
		sc->bufferIndex++;
		
		// Return the word
		return word;
	} else {
		// If the scanner is not set to split input by words
		
		// Allocate memory for the string
		int length = sc->bufferEnd - sc->bufferIndex;
		char *str = (char *)malloc(length + 1);
		
		// Copy the string from the buffer to the allocated memory
		memcpy(str, sc->buffer + sc->bufferIndex, length);
		str[length] = '\0'; // Add the null terminator
		
		// Update the buffer index
		sc->bufferIndex = sc->bufferEnd;
		
		// Return the string
		return str;
	}
}

// freeInputScanner frees the memory allocated for the input scanner
void freeInputScanner(inputScanner *sc) {
	free(sc->buffer); // Free the memory allocated for the buffer
	free(sc); // Free the memory allocated for the input scanner
}

