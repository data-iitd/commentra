#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000000

// ReadLongLines reads multiple lines of input from stdin.
// It uses a buffer to accumulate the input and reads line by line until it reaches the end of the file.
char** ReadLongLines(int times) {
	char** result = (char**)malloc(times * sizeof(char*));
	char* buffer = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
	int readBytes = 2;
	for (int i = 0; i < times; i++) {
		for (;;) {
			char* readBuf = fgets(buffer, MAX_LINE_LENGTH, stdin);
			readBytes += strlen(readBuf) + 1;
			if (feof(stdin)) {
				break;
			}
			if (ferror(stdin)) {
				return result;
			}
			if (strchr(readBuf, '\n') == NULL) {
				continue;
			}
			result[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
			strcpy(result[i], buffer);
			buffer = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
			break;
		}
	}
	// 先読みしてしまうようなので、戻しておく
	fseek(stdin, -readBytes, SEEK_CUR);
	return result;
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

// PrintList prints a list of integers separated by spaces.
void PrintList(int* list, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", list[i]);
		} else {
			printf(" %d", list[i]);
		}
	}
	printf("\n");
}

//