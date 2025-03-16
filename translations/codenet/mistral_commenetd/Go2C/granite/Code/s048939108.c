

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new scanner
void initScanner(struct Scanner *s) {
    s->r = stdin;
    s->buf = (char *)malloc(1000 * sizeof(char));
    s->p = 0;
}

// Next function to read the next token as a string
char *next(struct Scanner *s) {
    s->pre(s);
    int start = s->p;
    for (; s->p < 1000; s->p++) {
        if (s->buf[s->p] =='') {
            break;
        }
    }
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

// NextLine function to read the next line as a string
char *nextLine(struct Scanner *s) {
    s->pre(s);
    int start = s->p;
    s->p = 1000;
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

// NextInt function to read the next integer from the standard input
int nextInt(struct Scanner *s) {
    char *str = next(s);
    int result = atoi(str);
    free(str);
    return result;
}

// NextIntArray function to read an array of integers from the standard input
int *nextIntArray(struct Scanner *s) {
    s->pre(s);
    int start = s->p;
    int *result = (int *)malloc(1000 * sizeof(int));
    int i = 0;
    for (; s->p < 1000; s->p++) {
        if (s->p == 1000 || s->buf[s->p] =='') {
            char *str = (char *)malloc((s->p - start + 1) * sizeof(char));
            strncpy(str, s->buf + start, s->p - start);
            str[s->p - start] = '\0';
            result[i] = atoi(str);
            free(str);
            start = s->p + 1;
            i++;
        }
    }
    return result;
}

// Pre function to prepare the scanner for reading the next token
void pre(struct Scanner *s) {
    if (s->p >= 1000) {
        s->readLine(s);
        s->p = 0;
    }
}

// ReadLine function to read a line from the standard input
void readLine(struct Scanner *s) {
    free(s->buf);
    s->buf = (char *)malloc(1000 * sizeof(char));
    int i = 0;
    for (; i < 1000; i++) {
        char c = fgetc(s->r);
        if (c == '\n') {
            break;
        }
        s->buf[i] = c;
    }
    s->buf[i] = '\0';
}

int main() {
    struct Scanner s;
    initScanner(&s);
    char *S = next(&s);
    if (strncmp(S, "YAKI", 5) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

// Minimum function
int min(int a, int b) {
    // Determine the minimum of two integers
    if (a > b) {
        return b;
    }
    return a;
}

// Maximum function
int max(int a, int b) {
    // Determine the maximum of two integers
    if (a > b) {
        return a;
    }
    return b;
}

// Scanner structure definition
struct Scanner {
    FILE *r;
    char *buf;
    int p;
};

// Minimum function
int min(int a, int b) {
    // Determine the minimum of two integers
    if (a > b) {
        return b;
    }
    return a;
}

// Maximum function
int max(int a, int b) {
    // Determine the maximum of two integers
    if (a > b) {
        return a;
    }
    return b;
}

// Scanner structure definition
struct Scanner {
    FILE *r;
    char *buf;
    int p;
};

// Initialize a new scanner instance
void initScanner(struct Scanner *s) {
    s->r = stdin;
    s->buf = (char *)malloc(1000 * sizeof(char));
    s->p = 0;
}

// Next function to read the next token as a string
char *next(struct Scanner *s) {
    s->pre(s);
    int start = s->p;
    for (; s->p < 1000; s->p++) {
        if (s->buf[s->p] =='') {
            break;
        }
    }
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

// NextLine function to read the next line as a string
char *nextLine(struct Scanner *s) {
    s->pre(s);
    int start = s->p;
    s->p = 1000;
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

// NextInt function to read the next integer from the standard input
int nextInt(struct Scanner *s) {
    char *str = next(s);
    int result = atoi(str);
    free(str);
    return result;
}

// NextIntArray function to read an array of integers from the standard input
int *nextIntArray(struct Scanner *s) {
    s->pre(s);
    int start = s->p;
    int *result = (int *)malloc(1000 * sizeof(int));
    int i = 0;
    for (; s->p < 1000; s->p++) {
        if (s->p == 1000 || s->buf[s->p] =='') {
            char *str = (char *)malloc((s->p - start + 1) * sizeof(char));
            strncpy(str, s->buf + start, s->p - start);
            str[s->p - start] = '\0';
            result[i] = atoi(str);
            free(str);
            start = s->p + 1;
            i++;
        }
    }
    return result;
}

// Pre function to prepare the scanner for reading the next token
void pre(struct Scanner *s) {
    if (s->p >= 1000) {
        s->readLine(s);
        s->p = 0;
    }
}

// ReadLine function to read a line from the standard input
void readLine(struct Scanner *s) {
    free(s->buf);
    s->buf = (char *)malloc(1000 * sizeof(char));
    int i = 0;
    for (; i < 1000; i++) {
        char c = fgetc(s->r);
        if (c == '\n') {
            break;
        }
        s->buf[i] = c;
    }
    s->buf[i] = '\0';
}

// Minimum function
int min(int a, int b) {
    // Determine the minimum of two integers
    if (a > b) {
        return b;
    }
    return a;
}

// Maximum function
int max(int a, int b) {
    // Determine the maximum of two integers
    if (a > b) {
        return a;
    }
    return b;
}

// Scanner structure definition
struct Scanner {
    FILE *r;
    char *buf;
    int p;
};

// Initialize a new scanner instance
void initScanner(struct Scanner *s) {
    s->r = stdin;
    s->buf = (char *)malloc(1000 * sizeof(char));
    s->p = 0;
}

// Next function to read the next token as a string
char *next(struct Scanner *s) {
    s->pre(s);
    int start = s->p;
    for (; s->p < 1000; s->p++) {
        if (s->buf[s->p] =='') {
            break;
        }
    }
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

// NextLine function to read the next line as a string
char *nextLine(struct Scanner *s) {
    s->pre(s);
    int start = s->p;
    s->p = 1000;
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

// NextInt function to read the next integer from the standard input
int nextInt(struct Scanner *s) {
    char *str = next(s);
    int result = atoi(str);
    free(str);
    return result;
}

// NextIntArray function to read an array of integers from the standard input
int *nextIntArray(struct Scanner *s) {
    s->pre(s);
    int start = s->p;
    int *result = (int *)malloc(1000 * sizeof(int));
    int i = 0;
    for (; s->p < 1000; s->p++) {
        if (s->p == 1000 || s->buf[s->p] =='') {
            char *str = (char *)malloc((s->p - start + 1) * sizeof(char));
            strncpy(str, s->buf + start, s->p - start);
            str[s->p - start] = '\0';
            result[i] = atoi(str);
            free(str);
            start = s->p + 1;
            i++;
        }
    }
    return result;
}

// Pre function to prepare the scanner for reading the next token
void pre(struct Scanner *s) {
    if (s->p >= 1000) {
        s->readLine(s);
        s->p = 0;
    }
}

// ReadLine function to read a line from the standard input
void readLine(struct Scanner *s) {
    free(s->buf);
    s->buf = (char *)malloc(1000 * sizeof(char));
    int i = 0;
    for (; i < 1000; i++) {
        char c = fgetc(s->r);
        if (c == '\n') {
            break;
        }
        s->buf[i] = c;
    }
    s->buf[i] = '\0';
}

// Minimum function
int min(int a, int b) {
    // Determine the minimum of two integers
    if (a > b) {
        return b;
    }
    return a;
}

// Maximum function
int max(int a, int b) {
    // Determine the maximum of two integers
    if (a > b) {
        return a;
    }
    return b;
}

// Scanner structure definition
struct Scanner {
    FILE *r;
    char *buf;
    int p;
};

// Initialize a new scanner instance
void initScanner(struct Scanner *s) {
    s->r = stdin;
    s->buf = (char *)malloc(1000 * sizeof(char));
    s->p = 0;
}

// Next function to read the next token as a string
char *next(struct Scanner *s) {
    s->pre(s);
    int start = s->p;
    for (; s->p < 1000; s->p++) {
        if (s->buf[s->p] =='') {
            break;
        }
    }
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

// NextLine function to read the next line as a string
char *nextLine(struct Scanner *s) {
    s->pre(s);
    int start = s->p;
    s->p = 1000;
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

// NextInt function to read the next integer from the standard input
int nextInt(struct Scanner *s) {
    char *str = next(s);
    int result = atoi(str);
    free(str);
    return result;
}

// NextIntArray function to read an array of integers from the standard input
int *nextIntArray(struct Scanner *s) {
    s->pre(s);
    int start = s->p;
    int *result = (int *)malloc(1000 * sizeof(int));
    int i = 0;
    for (; s->p < 1000; s->p++) {
        if (s->p == 1000 || s->buf[s->p] =='') {
            char *str = (char *)malloc((s->p - start + 1) * sizeof(char));
            strncpy(str, s->buf + start, s->p - start);
            str[s->p - start] = '