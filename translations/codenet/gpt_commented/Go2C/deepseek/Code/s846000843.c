#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_TOKENS 1000
#define MAX_LINE_LENGTH 10000

typedef struct {
    char **tokens;
    int tokenCount;
} Io;

Io* newIo() {
    Io *io = (Io*)malloc(sizeof(Io));
    io->tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    io->tokenCount = 0;
    return io;
}

void flush(Io *io) {
    for (int i = 0; i < io->tokenCount; i++) {
        free(io->tokens[i]);
    }
    free(io->tokens);
    free(io);
}

char* nextLine(Io *io) {
    char *buffer = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(buffer, MAX_LINE_LENGTH, stdin);
    return buffer;
}

void nextToken(Io *io) {
    if (io->tokenCount >= MAX_TOKENS) {
        return;
    }
    char *line = nextLine(io);
    io->tokens[io->tokenCount] = (char*)malloc((strlen(line) + 1) * sizeof(char));
    strcpy(io->tokens[io->tokenCount], line);
    free(line);
    io->tokenCount++;
}

int nextInt(Io *io) {
    nextToken(io);
    return atoi(io->tokens[io->tokenCount - 1]);
}

float nextFloat(Io *io) {
    nextToken(io);
    return atof(io->tokens[io->tokenCount - 1]);
}

void printLn(Io *io, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    fprintf(stdout, "\n");
    va_end(args);
}

void printIntLn(Io *io, int *a, int n) {
    for (int i = 0; i < n; i++) {
        printLn(io, "%d", a[i]);
    }
}

void log(const char *name, int value) {
    fprintf(stderr, "%s=%d\n", name, value);
}

int abs(int a) {
    return a >= 0 ? a : -a;
}

int pow(int p, int q) {
    return (int)pow(p, q);
}

int min(int nums[], int size) {
    int res = nums[0];
    for (int i = 1; i < size; i++) {
        res = fmin(res, nums[i]);
    }
    return res;
}

int max(int nums[], int size) {
    int res = nums[0];
    for (int i = 1; i < size; i++) {
        res = fmax(res, nums[i]);
    }
    return res;
}

void sortAsc(int *a, int n) {
    qsort(a, n, sizeof(int), (int (*)(const void *, const void *))compareAsc);
}

void sortDesc(int *a, int n) {
    qsort(a, n, sizeof(int), (int (*)(const void *, const void *))compareDesc);
}

int compareAsc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compareDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    if (a == 0 && b == 0) {
        return 0;
    }
    return a * b / gcd(a, b);
}

int* cumSum(int *nums, int n) {
    int *sums = (int*)malloc((n + 1) * sizeof(int));
    sums[0] = 0;
    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    return sums;
}

int bisectLeft(int *nums, int left, int right, int target) {
    if (left == right) {
        if (nums[left] == target) {
            return left;
        } else if (nums[left] < target) {
            return left + 1;
        } else {
            return left;
        }
    }

    int mid = (left + right) / 2;
    if (nums[mid] == target) {
        return mid;
    }

    if (nums[mid] > target) {
        return bisectLeft(nums, left, mid, target);
    } else {
        return bisectLeft(nums, mid + 1, right, target);
    }
}

void permutations(int *nums, int n, int *stack, int stackSize, bool *used, int **result, int *resultSize) {
    if (stackSize == n) {
        result[*resultSize] = (int*)malloc(n * sizeof(int));
        memcpy(result[*resultSize], stack, n * sizeof(int));
        (*resultSize)++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            stack[stackSize] = nums[i];
            permutations(nums, n, stack, stackSize + 1, used, result, resultSize);
            used[i] = false;
        }
    }
}

void powerSet(int *nums, int n, int **result, int *resultSize) {
    int size = 1 << n;
    result[0] = (int*)malloc(0 * sizeof(int));
    (*resultSize)++;

    for (int i = 0; i < n; i++) {
        int max = (*resultSize);
        for (int j = 0; j < max; j++) {
            result[(*resultSize)] = (int*)malloc((j + 2) * sizeof(int));
            memcpy(result[(*resultSize)], result[j], j * sizeof(int));
            result[(*resultSize)][j] = nums[i];
            (*resultSize)++;
        }
    }
}

int combinationCount(int n, int m, int memo[10000][10000]) {
    if (n == m || m == 0) {
        return 1;
    }

    if (memo[n - 1][m - 1] != -1 && memo[n - 1][m] != -1) {
        return memo[n - 1][m - 1] + memo[n - 1][m];
    }

    int left = combinationCount(n - 1, m - 1, memo);
    int right = combinationCount(n - 1, m, memo);
    memo[n - 1][m - 1] = left;
    memo[n - 1][m] = right;
    return left + right;
}

int main() {
    Io *io = newIo();

    int n = nextInt(io);
    int aa[n];
    for (int i = 0; i < n; i++) {
        aa[i] = nextInt(io);
    }

    int *cumsum = cumSum(aa, n);
    int ans = 2020202020;

    for (int i = 1; i < n - 1; i++) {
        ans = fmin(ans, abs(cumsum[n] - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    printLn(io, "%d", ans);

    free(cumsum);
    flush(io);
    return 0;
}
