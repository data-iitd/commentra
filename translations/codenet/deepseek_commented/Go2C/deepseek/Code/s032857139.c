#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUMBERS 100000

// I/O functions for reading input efficiently.
char* readString() {
    static char buf[MAX_INPUT_SIZE];
    if (fgets(buf, sizeof(buf), stdin) != NULL) {
        buf[strcspn(buf, "\n")] = '\0'; // Remove newline character
        return buf;
    }
    return NULL;
}

int readInt() {
    char* str = readString();
    return atoi(str);
}

int* readIntArray(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = readInt();
    }
    return arr;
}

// Utility functions for dynamic programming.
int ChMin(int* updatedValue, int target) {
    if (*updatedValue > target) {
        *updatedValue = target;
        return 1;
    }
    return 0;
}

int ChMax(int* updatedValue, int target) {
    if (*updatedValue < target) {
        *updatedValue = target;
        return 1;
    }
    return 0;
}

int GetNthBit(int num, int nth) {
    return (num >> nth) & 1;
}

// Arithmetic functions for mathematical operations.
int Max(int n, ...) {
    va_list args;
    va_start(args, n);
    int max = va_arg(args, int);
    for (int i = 1; i < n; i++) {
        int current = va_arg(args, int);
        if (current > max) {
            max = current;
        }
    }
    va_end(args);
    return max;
}

int Min(int n, ...) {
    va_list args;
    va_start(args, n);
    int min = va_arg(args, int);
    for (int i = 1; i < n; i++) {
        int current = va_arg(args, int);
        if (current < min) {
            min = current;
        }
    }
    va_end(args);
    return min;
}

int CeilInt(int a, int b) {
    return (a + b - 1) / b;
}

int FloorInt(int a, int b) {
    return a / b;
}

int PowInt(int a, int e) {
    if (a < 0 || e < 0) {
        fprintf(stderr, "[argument error]: PowInt does not accept negative integers\n");
        exit(1);
    }

    int result = 1;
    for (int i = 0; i < e; i++) {
        result *= a;
    }
    return result;
}

int AbsInt(int a) {
    return a < 0 ? -a : a;
}

int Gcd(int a, int b) {
    if (a <= 0 || b <= 0) {
        fprintf(stderr, "[argument error]: Gcd only accepts two NATURAL numbers\n");
        exit(1);
    }
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int Lcm(int a, int b) {
    if (a <= 0 || b <= 0) {
        fprintf(stderr, "[argument error]: Gcd only accepts two NATURAL numbers\n");
        exit(1);
    }
    return (a / Gcd(a, b)) * b;
}

// Utility functions for string manipulation and permutation.
int* DeleteElement(int* s, int i, int size) {
    if (i < 0 || i >= size) {
        fprintf(stderr, "[index error]\n");
        exit(1);
    }
    int* n = (int*)malloc((size - 1) * sizeof(int));
    memcpy(n, s, i * sizeof(int));
    memcpy(n + i, s + i + 1, (size - i - 1) * sizeof(int));
    return n;
}

char* Concat(const char* s, const char* t) {
    int lenS = strlen(s);
    int lenT = strlen(t);
    char* n = (char*)malloc((lenS + lenT + 1) * sizeof(char));
    strcpy(n, s);
    strcat(n, t);
    return n;
}

char UpperRune(char r) {
    char str[2] = {r, '\0'};
    char* upperStr = strupr(str);
    return upperStr[0];
}

char LowerRune(char r) {
    char str[2] = {r, '\0'};
    char* lowerStr = strlwr(str);
    return lowerStr[0];
}

char ToggleRune(char r) {
    if (islower(r)) {
        return toupper(r);
    } else if (isupper(r)) {
        return tolower(r);
    }
    return r;
}

char* ToggleString(const char* s) {
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        result[i] = ToggleRune(s[i]);
    }
    result[len] = '\0';
    return result;
}

int Strtoi(const char* s) {
    char* endptr;
    int value = strtol(s, &endptr, 10);
    if (*endptr != '\0') {
        fprintf(stderr, "[argument error]: Strtoi only accepts integer string\n");
        exit(1);
    }
    return value;
}

// Functions for generating permutations.
int** CalcFactorialPatterns(const int* elements, int size, int* returnSize) {
    int totalPatterns = 1;
    for (int i = 2; i <= size; i++) {
        totalPatterns *= i;
    }
    int** res = (int**)malloc(totalPatterns * sizeof(int*));
    *returnSize = totalPatterns;

    int* indices = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < totalPatterns; i++) {
        res[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            res[i][j] = elements[indices[j]];
        }
        int k;
        for (k = size - 2; k >= 0 && indices[k] >= indices[k + 1]; k--);
        if (k == -1) break;
        int l;
        for (l = size - 1; indices[k] >= indices[l]; l--);
        int temp = indices[k];
        indices[k] = indices[l];
        indices[l] = temp;
        for (int