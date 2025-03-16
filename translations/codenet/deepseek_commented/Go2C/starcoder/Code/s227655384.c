#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ReadLongLines reads multiple lines of input from stdin.
// It uses a buffer to accumulate the input and reads line by line until it reaches the end of the file.
char** ReadLongLines(int times) {
	char** result = (char**)malloc(sizeof(char*) * times);
	char* buffer = (char*)malloc(sizeof(char) * 1024);
	int readBytes = 2;
	for (int i = 0; i < times; i++) {
		for (int j = 0; j < 1024; j++) {
			buffer[j] = 0;
		}
		for (int j = 0; j < 1024; j++) {
			char c = getchar();
			if (c == '\n') {
				result[i] = (char*)malloc(sizeof(char) * (j + 1));
				memcpy(result[i], buffer, sizeof(char) * (j + 1));
				readBytes += j + 1;
				break;
			}
			buffer[j] = c;
			readBytes++;
		}
	}
	// 先読みしてしまうようなので、戻しておく
	fseek(stdin, -readBytes, SEEK_CUR);
	return result;
}

// Console is a struct for formatted output.
// It wraps a bufio.Writer to improve performance by reducing the number of system calls.
typedef struct {
	FILE* writer;
} Console;

// NewConsole creates a new Console instance.
Console NewConsole() {
	Console con;
	con.writer = stdout;
	return con;
}

// Printf prints a formatted string to the console.
void Printf(Console con, char* format,...) {
	va_list args;
	va_start(args, format);
	vfprintf(con.writer, format, args);
	va_end(args);
}

// Println prints a line to the console.
void Println(Console con, char* s) {
	fprintf(con.writer, "%s\n", s);
}

// Close flushes the writer and closes the console.
void Close(Console con) {
	fflush(con.writer);
}

// Flush flushes the writer to ensure all data is written to the output.
void Flush(Console con) {
	fflush(con.writer);
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	Console con = NewConsole();
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			Printf(con, "%d", list[i]);
		} else {
			Printf(con, " %d", list[i]);
		}
	}
	Println(con, "");
}

int main() {
	Console con = NewConsole();
	char** lines = ReadLongLines(4);

	// Split the second line into individual elements and add them to the map.
	char* a = (char*)malloc(sizeof(char) * 1024);
	strcpy(a, lines[1]);
	char* p = strtok(a, " ");
	int* m = (int*)malloc(sizeof(int) * 200000);
	int mSize = 0;
	while (p!= NULL) {
		int n = atoi(p);
		m[mSize] = n;
		mSize++;
		p = strtok(NULL, " ");
	}
	free(a);

	// Process the fourth line to toggle the presence of elements in the map.
	char* b = (char*)malloc(sizeof(char) * 1024);
	strcpy(b, lines[3]);
	p = strtok(b, " ");
	int* result = (int*)malloc(sizeof(int) * 200000);
	int resultSize = 0;
	while (p!= NULL) {
		int n = atoi(p);
		int found = 0;
		for (int i = 0; i < mSize; i++) {
			if (m[i] == n) {
				found = 1;
				break;
			}
		}
		if (found) {
			for (int i = 0; i < mSize; i++) {
				if (m[i] == n) {
					m[i] = m[mSize - 1];
					mSize--;
					break;
				}
			}
		} else {
			m[mSize] = n;
			mSize++;
		}
		p = strtok(NULL, " ");
	}
	free(b);

	// Extract the unique elements from the map and sort them.
	int* unique = (int*)malloc(sizeof(int) * mSize);
	int uniqueSize = 0;
	for (int i = 0; i < mSize; i++) {
		int found = 0;
		for (int j = 0; j < uniqueSize; j++) {
			if (unique[j] == m[i]) {
				found = 1;
				break;
			}
		}
		if (!found) {
			unique[uniqueSize] = m[i];
			uniqueSize++;
		}
	}
	free(m);

	// Print the sorted list of unique elements.
	for (int i = 0; i < uniqueSize; i++) {
		Printf(con, "%d\n", unique[i]);
	}
	free(unique);
	free(lines);
	Close(con);
}

