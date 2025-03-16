
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Create a struct to store the counts of integers
typedef struct {
	int key;
	int value;
} Map;

// Create a function to read an integer from stdin
int readInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Create a function to read a line of input from stdin
char* readLine() {
	char* line = malloc(1000000);
	fgets(line, 1000000, stdin);
	return line;
}

// Create a function to sort the map by key in descending order
void sortMap(Map* map, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (map[i].key < map[j].key) {
				Map temp = map[i];
				map[i] = map[j];
				map[j] = temp;
			}
		}
	}
}

// Create a function to calculate the sum based on the conditions
int calculateSum(Map* map, int size, int rest) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (map[i].value >= rest) {
			sum += rest * map[i].key;
			break;
		}
		sum += map[i].value * map[i].key;
		rest -= map[i].value;
	}
	return sum;
}

// Create a function to perform the operations
int performOperations(Map* map, int size, int rest) {
	// Read the number of initial elements (N) and the number of operations (M)
	int N = readInt();
	int M = readInt();
	
	// Read N integers and store their counts in the map
	for (int i = 0; i < N; i++) {
		map[i].key = readInt();
		map[i].value++;
	}
	
	// Perform M operations to update the map with new integers and their counts
	for (int i = 0; i < M; i++) {
		int B = readInt();
		int C = readInt();
		map[C].value += B;
	}
	
	// Sort the map by key in descending order
	sortMap(map, size);
	
	// Calculate the sum based on the conditions
	int sum = calculateSum(map, size, rest);
	
	// Print the calculated sum
	printf("%d\n", sum);
	
	return 0;
}

// Create a function to free the memory allocated for the map
void freeMap(Map* map, int size) {
	for (int i = 0; i < size; i++) {
		free(map[i].key);
		free(map[i].value);
	}
	free(map);
}

// Create a function to free the memory allocated for the line
void freeLine(char* line) {
	free(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to perform the operations and free the memory allocated for the map and the line
int performOperationsAndFree(int size) {
	// Allocate memory for the map
	Map* map = malloc(size * sizeof(Map));
	
	// Perform the operations
	int result = performOperations(map, size, size);
	
	// Free the memory allocated for the map and the line
	freeMapAndLine(map, size, readLine());
	
	return result;
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map
void freeMap(Map* map, int size) {
	for (int i = 0; i < size; i++) {
		free(map[i].key);
		free(map[i].value);
	}
	free(map);
}

// Create a function to free the memory allocated for the line
void freeLine(char* line) {
	free(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory allocated for the map and the line
void freeMapAndLine(Map* map, int size, char* line) {
	freeMap(map, size);
	freeLine(line);
}

// Create a function to free the memory 