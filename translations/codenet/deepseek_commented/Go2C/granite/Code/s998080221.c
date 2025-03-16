
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bufReader is a struct to efficiently read input.
typedef struct {
    char *buf;
    int i;
    int size;
} bufReader;

// Initialize global reader and writer for input and output operations.
bufReader reader;
FILE *writer = stdout;

// readLine reads the next line from the input and stores it in the buffer.
void readLine() {
    if (reader.i < reader.size) {
        return;
    }
    reader.size = 0;
    reader.i = 0;
    while (1) {
        char line[1024];
        fgets(line, sizeof(line), stdin);
        reader.size += strlen(line);
        reader.buf = (char *)realloc(reader.buf, reader.size);
        strcat(reader.buf, line);
        if (strchr(line, '\n')!= NULL) {
            break;
        }
    }
}

// next returns the next token (word) from the input.
char *next() {
    readLine();
    int from = reader.i;
    while (reader.i < reader.size && reader.buf[reader.i]!='') {
        reader.i++;
    }
    char *s = (char *)malloc(reader.i - from + 1);
    strncpy(s, reader.buf + from, reader.i - from);
    s[reader.i - from] = '\0';
    reader.i++;
    return s;
}

// nextLine returns the next line from the input.
char *nextLine() {
    readLine();
    char *s = (char *)malloc(reader.size - reader.i + 1);
    strncpy(s, reader.buf + reader.i, reader.size - reader.i);
    s[reader.size - reader.i] = '\0';
    reader.i = reader.size;
    return s;
}

// out prints the arguments to the output.
void out(int argc,...) {
    va_list args;
    va_start(args, argc);
    for (int i = 0; i < argc; i++) {
        if (i > 0) {
            fprintf(writer, " ");
        }
        fprintf(writer, "%d", va_arg(args, int));
    }
    fprintf(writer, "\n");
    va_end(args);
}

// max returns the maximum of two int values.
int max(int x, int y) {
    return x > y? x : y;
}

// min returns the minimum of two int values.
int min(int x, int y) {
    return x < y? x : y;
}

// abs returns the absolute value of an int.
int abs(int x) {
    return x < 0? -x : x;
}

// joinInts joins an array of int values into a string with a separator.
char *joinInts(int *a, int n, char *sep) {
    char *s = (char *)malloc(1024);
    s[0] = '\0';
    for (int i = 0; i < n; i++) {
        char buf[16];
        sprintf(buf, "%d", a[i]);
        strcat(s, buf);
        if (i < n - 1) {
            strcat(s, sep);
        }
    }
    return s;
}

// divUp returns the ceiling of the division of x by y.
int divUp(int x, int y) {
    return (x + y - 1) / y;
}

// gcd returns the greatest common divisor of two int values.
int gcd(int x, int y) {
    if (x < y) {
        int t = x;
        x = y;
        y = t;
    }
    while (y!= 0) {
        int t = x % y;
        x = y;
        y = t;
    }
    return x;
}

// lcm returns the least common multiple of two int values.
int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

// pow returns the result of raising x to the power of y.
int pow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

// main function calls solve and flushes the writer at the end.
int main() {
    int N, _;
    scanf("%d %d", &N, &_);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int maxProfit = 0;
    int maxCnt = 0;
    int maxA = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        int profit = max(0, maxA - A[i]);
        if (maxProfit < profit) {
            maxProfit = profit;
            maxCnt = 1;
        } else if (maxProfit == profit) {
            maxCnt++;
        }
        maxA = max(maxA, A[i]);
    }
    out(1, maxCnt);
    return 0;
}
