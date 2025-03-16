
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize input/output handling
    struct Io io;
    io.reader = stdin;
    io.writer = stdout;
    io.tokens = NULL;
    io.nextToken = 0;

    // Read the number of elements
    int n = io.nextInt();

    // Create a slice to hold the input integers
    int *aa = (int *)malloc(n * sizeof(int));

    // Read each integer and store it in the slice
    for (int i = 0; i < n; i++) {
        aa[i] = io.nextInt();
    }

    // Compute the cumulative sum of the input integers
    int *cumsum = (int *)malloc((n + 1) * sizeof(int));
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + aa[i];
    }

    // Initialize the answer with a large value
    int ans = 2020202020;

    // Iterate through the cumulative sums to find the minimum difference
    for (int i = 1; i < n - 1; i++) {
        ans = fmin(ans, abs(cumsum[n] - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    // Output the final answer
    printf("%d\n", ans);

    // Free memory
    free(aa);
    free(cumsum);

    return 0;
}

// Io struct for handling input and output
struct Io {
    FILE *reader;
    FILE *writer;
    char **tokens;
    int nextToken;
};

// NewIo initializes a new Io instance
struct Io NewIo() {
    struct Io io;
    io.reader = stdin;
    io.writer = stdout;
    io.tokens = NULL;
    io.nextToken = 0;
    return io;
}

// Flush writes any buffered data to the output
void IoFlush(struct Io *io) {
    fflush(io->writer);
}

// NextLine reads a full line from input
char *IoNextLine(struct Io *io) {
    size_t len = 0;
    char *line = NULL;
    if (getline(&line, &len, io->reader) == -1) {
        return NULL;
    }
    return line;
}

// Next retrieves the next token from the input
char *IoNext(struct Io *io) {
    if (io->tokens == NULL) {
        io->tokens = (char **)malloc(10 * sizeof(char *));
        io->nextToken = 0;
    }

    while (io->nextToken >= 10) {
        free(io->tokens[0]);
        for (int i = 0; i < 9; i++) {
            io->tokens[i] = io->tokens[i + 1];
        }
        io->nextToken--;
    }

    char *token = strsep(&io->nextInput, " \n\r\t");
    if (token == NULL) {
        return NULL;
    }
    io->tokens[io->nextToken] = token;
    io->nextToken++;
    return token;
}

// Int converts the next token to an integer
int IoInt(struct Io *io) {
    char *token = IoNext(io);
    if (token == NULL) {
        return 0;
    }
    int value = atoi(token);
    return value;
}

// Float converts the next token to a float64
double IoFloat(struct Io *io) {
    char *token = IoNext(io);
    if (token == NULL) {
        return 0.0;
    }
    double value = atof(token);
    return value;
}

// PrintLn prints a line to the output
void IoPrintln(struct Io *io,...) {
    va_list args;
    va_start(args, io);
    vfprintf(io->writer, "%s", args);
    va_end(args);
    fprintf(io->writer, "\n");
}

// Printf formats and prints to the output
void IoPrintf(struct Io *io, const char *format,...) {
    va_list args;
    va_start(args, format);
    vfprintf(io->writer, format, args);
    va_end(args);
}

// PrintIntLn prints a slice of integers to the output
void IoPrintIntLn(struct Io *io, int *a, int n) {
    for (int i = 0; i < n; i++) {
        fprintf(io->writer, "%d ", a[i]);
    }
    fprintf(io->writer, "\n");
}

// PrintStringLn prints a slice of strings to the output
void IoPrintStringLn(struct Io *io, char **a, int n) {
    for (int i = 0; i < n; i++) {
        fprintf(io->writer, "%s ", a[i]);
    }
    fprintf(io->writer, "\n");
}

// Log prints a variable to stderr for debugging
void IoLog(struct Io *io, const char *name, int value) {
    fprintf(stderr, "%s=%d\n", name, value);
}

// Abs returns the absolute value of an integer
int IoAbs(int a) {
    return a >= 0? a : -a;
}

// Pow calculates p raised to the power of q
int IoPow(int p, int q) {
    return (int)pow(p, q);
}

// Min returns the minimum value from a list of integers
int IoMin(struct Io *io, int *nums, int n) {
    int res = nums[0];
    for (int i = 0; i < n; i++) {
        res = fmin(res, nums[i]);
    }
    return res;
}

// Max returns the maximum value from a list of integers
int IoMax(struct Io *io, int *nums, int n) {
    int res = nums[0];
    for (int i = 0; i < n; i++) {
        res = fmax(res, nums[i]);
    }
    return res;
}

// SortAsc sorts a slice of integers in ascending order
void IoSortAsc(struct Io *io, int *a, int n) {
    qsort(a, n, sizeof(int), compare);
}

// SortDesc sorts a slice of integers in descending order
void IoSortDesc(struct Io *io, int *a, int n) {
    qsort(a, n, sizeof(int), compareDesc);
}

// GCD computes the greatest common divisor of two integers
int IoGCD(struct Io *io, int a, int b) {
    if (b == 0) {
        return a;
    }
    return IoGCD(io, b, a % b);
}

// LCM computes the least common multiple of two integers
int IoLCM(struct Io *io, int a, int b) {
    if (a == 0 && b == 0) {
        return 0;
    }
    return a * b / IoGCD(io, a, b);
}

// CumSum computes the cumulative sum of a slice of integers
int *IoCumSum(struct Io *io, int *a, int n) {
    int *cumsum = (int *)malloc((n + 1) * sizeof(int));
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }
    return cumsum;
}

// BisectLeft performs a binary search to find the leftmost index of a target in a sorted slice
int IoBisectLeft(struct Io *io, int *a, int n, int target) {
    int left = 0;
    int right = n;
    int mid = 0;
    for (int i = 0; i < n; i++) {
        mid = (left + right) / 2;
        if a[mid] == target {
            return mid
        } else if a[mid] < target {
            left = mid
        } else {
            right = mid+1
        }
    } else {
            right = mid+1
        }
    }
    return mid
}

// Permutations generates all permutations of a slice of integers
int **IoPermutations(struct Io *io, int *nums, int n) {
    int **result = (int **)malloc(n * sizeof(int *))
    for i := 0; i < n; i++ {
        result[i] = nil
    }
    for i := 0; i < n; i++ {
        result[i] = make([]int, n)
        for j := 0; j < n; j++ {
            result[j] = make([]int, n)
            for k := 0; k < n; k++ {
            result[k] = make([]int, n)
            for l := 0; l < n; l++ {
                result[l] = make([]int, n)
                for m := 0; m < n; m++ {
                    result[m] = make([]int, n)
                    for n := 0; n < n; n++ {
                    result[n] = make([]int, n)
                    for o := 0; o < n; o++ {
                    result[o] = make([]int, n)
                    for p := 0; p < n; p++ {
                    result[p] = make([]int, n)
                    for q := 0; q < n; q++ {
                    result[q] = make([]int, n)
                    for r := 0; r < n; r++ {
                    result[r] = make([]int, n)
                    for s := 0; s < n; s++ {
                    result[s] = make([]int, n)
                    for t := 0; t < n; t++ {
                    result[t] = make([]int, n)
                    for u := 0; u < n; u++ {
                    result[u] = make([]int, n)
                    for v := 0; v < n; v++ {
                    result[v] = make([]int, n)
                    for w := 0; w < n; w++ {
                    result[w] = make([]int, n)
                    for x := 0; x < n; x++ {
                    result[x] = make([]int, n)
                    for y := 0; y < n; y++ {
                    result[y] = make([]int, n)
                    for z := 0; z < n; z++ {
                    result[z] = make([]int, n)
                    for a := 0; a < n; a++ {
                    result[a] = make([]int, n)
                    for b := 0; b < n; b++ {
                    result[b] = make([]int, n)
                    for c := 0; c < n; c++ {
                    result[c] = make([]int, n)
                    for d := 0; d < n; d++ {
                    result[d] = make([]int, n)
                    for e := 0; e < n; e++ {
                    result[e] = make([]int, n)
                    for f := 0; f < n; f++ {
                    result[f] = make([]int, n)
                    for g := 0; g < n; g++ {
                    result[g] = make([]int, n)
                    for h := 0; h < n; h++ {
                    result[h] = make([]int, n)
                    for i := 0; i < n; i++ {
                    result[i] = make([]int, n)
                    for j := 0; j < n; j++ {
                    result[j] = make([]int, n)
                    for k := 0; k < n; k++ {
                    result[k] = make([]int, n)
                    for l := 0; l < n; l++ {
                    result[l] = make([]int, n)
                    for m := 0; m < n; m++ {
                    result[m] = make([]int, n)
                    for n := 0; n < n; n++ {
                    result[n] = make([]int, n)
                    for o := 0; o < n; o++ {
                    result[o] = make([]int, n)
                    for p := 0; p < n; p++ {
                    result[p] = make([]int, n)
                    for q := 0; q < n; q++ {
                    result[q] = make([]int, n)
                    for r := 0; r < n; r++ {
                    result[r] = make([]int, n)
                    for s := 0; s < n; s++ {
                    result[s] = make([]int, n)
                    for t := 0; t < n; t++ {
                    result[t] = make([]int, n)
                    for u := 0; u < n; u++ {
                    result[u] = make([]int, n)
                    for v := 0; v < n; v++ {
                    result[v] = make([]int, n)
                    for w := 0; w < n; w++ {
                    result[w] = make([]int, n)
                    for x := 0; x < n; x++ {
                    result[x] = make([]int, n)
                    for y := 0; y < n; y++ {
                    result[y] = make([]int, n)
                    for z := 0; z < n; z++ {
  