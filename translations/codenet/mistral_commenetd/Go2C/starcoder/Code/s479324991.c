#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new scanner object
typedef struct {
	char *buf;
	int p;
	int size;
} Scanner;

// Create a new scanner object
Scanner *NewScanner() {
	Scanner *s = (Scanner *)malloc(sizeof(Scanner));
	s->r = (char *)malloc(1000);
	s->p = 0;
	s->size = 1000;
	return s;
}

// Read a single token from the standard input
char *Next(Scanner *s) {
	s->pre();
	int start = s->p;
	while (s->p < s->size && s->buf[s->p]!='') {
		s->p++;
	}
	char *result = (char *)malloc(s->p - start + 1);
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++;
	return result;
}

// Read a line from the standard input
char *NextLine(Scanner *s) {
	s->pre();
	int start = s->p;
	s->p = s->size;
	char *result = (char *)malloc(s->p - start + 1);
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	return result;
}

// Read an integer from the standard input
int NextInt(Scanner *s) {
	char *v = Next(s);
	return atoi(v);
}

// Read an array of integers from the standard input
int *NextIntArray(Scanner *s) {
	s->pre();
	int start = s->p;
	int *result = (int *)malloc(sizeof(int));
	int i = 0;
	while (s->p < s->size && s->buf[s->p]!='') {
		s->p++;
	}
	char *v = (char *)malloc(s->p - start + 1);
	strncpy(v, s->buf + start, s->p - start);
	v[s->p - start] = '\0';
	result[i++] = atoi(v);
	start = s->p + 1;
	while (s->p < s->size) {
		while (s->p < s->size && s->buf[s->p] =='') {
			s->p++;
		}
		if (s->p == s->size) {
			break;
		}
		while (s->p < s->size && s->buf[s->p]!='') {
			s->p++;
		}
		char *v = (char *)malloc(s->p - start + 1);
		strncpy(v, s->buf + start, s->p - start);
		v[s->p - start] = '\0';
		result = (int *)realloc(result, sizeof(int) * i);
		result[i++] = atoi(v);
		start = s->p + 1;
	}
	v = (char *)malloc(s->p - start + 1);
	strncpy(v, s->buf + start, s->p - start);
	v[s->p - start] = '\0';
	result = (int *)realloc(result, sizeof(int) * i);
	result[i++] = atoi(v);
	return result;
}

// Read a map from the standard input
int *NextMap(Scanner *s) {
	s->pre();
	int start = s->p;
	int *result = (int *)malloc(sizeof(int));
	int i = 0;
	while (s->p < s->size && s->buf[s->p]!='') {
		s->p++;
	}
	char *v = (char *)malloc(s->p - start + 1);
	strncpy(v, s->buf + start, s->p - start);
	v[s->p - start] = '\0';
	result[i++] = atoi(v);
	start = s->p + 1;
	while (s->p < s->size) {
		while (s->p < s->size && s->buf[s->p] =='') {
			s->p++;
		}
		if (s->p == s->size) {
			break;
		}
		while (s->p < s->size && s->buf[s->p]!='') {
			s->p++;
		}
		char *v = (char *)malloc(s->p - start + 1);
		strncpy(v, s->buf + start, s->p - start);
		v[s->p - start] = '\0';
		result = (int *)realloc(result, sizeof(int) * i);
		result[i++] = atoi(v);
		start = s->p + 1;
	}
	v = (char *)malloc(s->p - start + 1);
	strncpy(v, s->buf + start, s->p - start);
	v[s->p - start] = '\0';
	result = (int *)realloc(result, sizeof(int) * i);
	result[i++] = atoi(v);
	return result;
}

// Prepare the scanner for the next read operation
void pre(Scanner *s) {
	if (s->p >= s->size) {
		readLine(s);
		s->p = 0;
	}
}

// Read a line from the standard input
void readLine(Scanner *s) {
	s->size = 1000;
	while (1) {
		int len = 0;
		char *l = (char *)malloc(s->size);
		l[len++] = fgetc(stdin);
		while (l[len - 1]!= '\n') {
			if (len == s->size) {
				s->size *= 2;
				l = (char *)realloc(l, s->size);
			}
			l[len++] = fgetc(stdin);
		}
		l[len - 1] = '\0';
		if (s->buf == NULL) {
			s->buf = l;
		} else {
			s->buf = (char *)realloc(s->buf, strlen(s->buf) + len + 1);
			strcat(s->buf, l);
		}
		if (feof(stdin)) {
			free(l);
			break;
		}
		free(l);
	}
}

// Translate the above Go code to C and end with comment "