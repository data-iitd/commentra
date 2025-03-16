#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
} Value;

typedef struct {
    Value *values;
    int count;
} Values;

Value readLine(FILE *file) {
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        Value v;
        v.data = (char *)malloc(strlen(buffer) + 1);
        strcpy(v.data, buffer);
        v.size = strlen(buffer);
        return v;
    }
    Value empty = {NULL, 0};
    return empty;
}

Values readLines(FILE *file, int n) {
    Values vs;
    vs.values = (Value *)malloc(n * sizeof(Value));
    vs.count = n;
    for (int i = 0; i < n; i++) {
        vs.values[i] = readLine(file);
    }
    return vs;
}

int parseInt(Value v) {
    return atoi(v.data);
}

double parseDouble(Value v) {
    return atof(v.data);
}

int countPointsWithinDistance(Values points, int n, double d) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        double x = parseDouble(points.values[i]);
        double y = parseDouble(points.values[i + 1]);
        double distance = sqrt(x * x + y * y);
        if (distance <= d) {
            count++;
        }
    }
    return count;
}

int main() {
    Value firstLine = readLine(stdin);
    int N = parseInt(firstLine);
    int D = parseInt(firstLine + 1);

    Values points = readLines(stdin, N);

    int result = countPointsWithinDistance(points, N, D);
    printf("%d\n", result);

    for (int i = 0; i < N; i++) {
        free(points.values[i].data);
    }
    free(points.values);
    free(firstLine.data);

    return 0;
}
