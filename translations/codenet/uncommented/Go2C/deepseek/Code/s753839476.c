#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double AbsDiffFloat64(double n1, double n2) {
    return fabs(n1 - n2);
}

typedef struct {
    FILE *input;
    FILE *output;
} IO;

IO* NewIO() {
    IO *io = (IO*)malloc(sizeof(IO));
    io->input = stdin;
    io->output = stdout;
    return io;
}

void CloseIO(IO *io) {
    fclose(io->output);
}

char* ScanString() {
    char *line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        free(line);
        return NULL;
    }
    return line;
}

char** ScanStrings(int n) {
    char **strs = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        strs[i] = ScanString();
    }
    return strs;
}

char** Scan2DGraph(int y) {
    char **strs = (char**)malloc(y * sizeof(char*));
    for (int i = 0; i < y; i++) {
        strs[i] = ScanString();
    }
    return strs;
}

int ScanInt() {
    int num;
    scanf("%d", &num);
    return num;
}

double ScanFloat64() {
    double num;
    scanf("%lf", &num);
    return num;
}

double* ScanFloat64s(int n) {
    double *floats = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        floats[i] = ScanFloat64();
    }
    return floats;
}

void Println(FILE *output, double a) {
    fprintf(output, "%.0f\n", a);
}

int main() {
    IO *io = NewIO();
    int n = ScanInt();
    double t = ScanFloat64();
    double a = ScanFloat64();
    double *heights = ScanFloat64s(n);

    double minDiff = AbsDiffFloat64(t - heights[0] * 0.006, a);
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        double diff = AbsDiffFloat64(t - heights[i] * 0.006, a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i;
        }
    }
    Println(io->output, minIdx + 1);
    CloseIO(io);
    return 0;
}
