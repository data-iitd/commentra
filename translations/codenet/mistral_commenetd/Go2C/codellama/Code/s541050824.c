// Importing required packages
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initializing variables
struct bufReader {
	FILE *file;
	char *buffer;
	int bufferSize;
};

struct bufReader reader = {
	stdin,
	(char *) malloc(0),
	0
};

FILE *writer = stdout;

