
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new scanner
struct scanner {
	FILE *r;
	char *buf;
	int p;
};

// Initialize a new scanner instance
struct scanner *newScanner() {
	struct scanner *s = malloc(sizeof(struct scanner));
	s->r = fopen(NULL, "r");
	s->buf = NULL;
	s->p = 0;
	return s;
}

// Next function to read the next token as a string
char *next(struct scanner *s) {
	pre(s);
	int start = s->p;
	while (s->p < strlen(s->buf)) {
		if (s->buf[s->p] =='') {
			break;
		}
		s->p++;
	}
	char *result = malloc(sizeof(char) * (s->p - start + 1));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++;
	return result;
}

// NextLine function to read the next line as a string
char *nextLine(struct scanner *s) {
	pre(s);
	int start = s->p;
	s->p = strlen(s->buf);
	char *result = malloc(sizeof(char) * (s->p - start + 1));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	return result;
}

// NextInt function to read the next integer from the standard input
int nextInt(struct scanner *s) {
	char *v = next(s);
	return atoi(v);
}

// NextIntArray function to read an array of integers from the standard input
int *nextIntArray(struct scanner *s) {
	pre(s);
	int start = s->p;
	int *result = malloc(sizeof(int) * 100);
	int i = 0;
	while (s->p < strlen(s->buf) + 1) {
		if (s->p == strlen(s->buf) || s->buf[s->p] =='') {
			char *v = malloc(sizeof(char) * (s->p - start + 1));
			strncpy(v, s->buf + start, s->p - start);
			v[s->p - start] = '\0';
			result[i] = atoi(v);
			free(v);
			i++;
			start = s->p + 1;
		}
		s->p++;
	}
	return result;
}

// Pre function to prepare the scanner for reading the next token
void pre(struct scanner *s) {
	if (s->p >= strlen(s->buf)) {
		readLine(s);
		s->p = 0;
	}
}

// ReadLine function to read a line from the standard input
void readLine(struct scanner *s) {
	free(s->buf);
	s->buf = NULL;
	s->p = 0;
	int len = 0;
	int c;
	while (1) {
		c = fgetc(s->r);
		if (c == EOF) {
			break;
		}
		if (len == 0) {
			s->buf = malloc(sizeof(char) * 1000);
		} else {
			s->buf = realloc(s->buf, sizeof(char) * (len + 1000));
		}
		s->buf[len] = c;
		len++;
		if (c == '\n') {
			break;
		}
	}
	s->buf[len] = '\0';
}



