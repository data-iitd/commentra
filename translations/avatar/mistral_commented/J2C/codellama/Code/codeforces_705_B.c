
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct FastReader {
    FILE *br;
    char *buf;
    int size;
    int len;
    char *cur;
    char *end;
};

struct FastReader *new_FastReader() {
    struct FastReader *fr = (struct FastReader *)malloc(sizeof(struct FastReader));
    fr->br = stdin;
    fr->size = 1024;
    fr->buf = (char *)malloc(fr->size * sizeof(char));
    fr->len = 0;
    fr->cur = fr->buf;
    fr->end = fr->buf + fr->size;
    return fr;
}

char *next(struct FastReader *fr) {
    while (fr->cur == fr->end) {
        fr->len = fread(fr->buf, 1, fr->size, fr->br);
        fr->cur = fr->buf;
        fr->end = fr->buf + fr->len;
    }
    return fr->cur++;
}

int nextInt(struct FastReader *fr) {
    char *s = next(fr);
    int n = 0;
    while (*s >= '0' && *s <= '9') {
        n = n * 10 + *s - '0';
        s = next(fr);
    }
    return n;
}

long long nextLong(struct FastReader *fr) {
    char *s = next(fr);
    long long n = 0;
    while (*s >= '0' && *s <= '9') {
        n = n * 10 + *s - '0';
        s = next(fr);
    }
    return n;
}

double nextDouble(struct FastReader *fr) {
    char *s = next(fr);
    double n = 0;
    while (*s >= '0' && *s <= '9') {
        n = n * 10 + *s - '0';
        s = next(fr);
    }
    return n;
}

char *nextLine(struct FastReader *fr) {
    char *s = next(fr);
    char *str = (char *)malloc(1024 * sizeof(char));
    int i = 0;
    while (*s != '\n') {
        str[i++] = *s;
        s = next(fr);
    }
    str[i] = '\0';
    return str;
}

struct FastReader *scan = new_FastReader();  // Creating an instance of FastReader

int main() {
    int t = nextInt(scan);  // Reading the number of test cases
    int *arr = (int *)malloc(t * sizeof(int));  // Creating an integer array of size 't' to store the input

    for (int i = 0; i < t; i++) {  // Iterating through the array
        arr[i] = nextInt(scan);  // Reading each element

        if (arr[i] == 1) {  // Checking if the current element is 1
            if (prevWinner == 0) {  // If the previous winner was 0
                prevWinner = 2;  // Update the 'prevWinner' variable to 2
            }

            if ((arr[i] - 1) % 2 == 0) {  // Checking the parity of the current element's index
                printf("%d\n", prevWinner == 0 ? 2 : 1);  // Printing the output based on the 'prevWinner' value
                prevWinner = (prevWinner == 0 ? 2 : 1);  // Updating the 'prevWinner' variable for the next iteration
            }
        }
    }
}

int prevWinner = 0;  // Initializing the 'prevWinner' variable to 0

