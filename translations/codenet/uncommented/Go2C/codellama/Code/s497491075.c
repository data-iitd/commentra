#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char *str;
    int len;
} Value;

typedef struct {
    Value *values;
    int len;
} Values;

void Run(FILE *r, FILE *w) {
    Scanner sc = NewScanner(r);

    int a[2];
    fscanf(r, "%d %d", &a[0], &a[1]);
    int N = a[0], D = a[1];

    int lines[N][2];
    for (int i = 0; i < N; i++) {
        fscanf(r, "%d %d", &lines[i][0], &lines[i][1]);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        double d = sqrt(lines[i][0] * lines[i][0] + lines[i][1] * lines[i][1]);
        if (D >= d) {
            count++;
        }
    }
    fprintf(w, "%d\n", count);
}

Scanner NewScanner(FILE *r) {
    Scanner sc;
    sc.values = (Value *)malloc(sizeof(Value) * 1000);
    sc.len = 0;
    return sc;
}

Value ReadLine(Scanner *sc) {
    if (fgets(sc->values[sc->len].str, 1000, r) != NULL) {
        sc->values[sc->len].len = strlen(sc->values[sc->len].str);
        sc->len++;
        return sc->values[sc->len - 1];
    }
    panic("scan error");
}

Values ReadLines(Scanner *sc, int n) {
    Values values;
    values.values = (Value *)malloc(sizeof(Value) * n);
    values.len = 0;
    for (int i = 0; i < n; i++) {
        values.values[i] = ReadLine(sc);
    }
    return values;
}

int String(Value v) {
    return atoi(v.str);
}

int *Ints(Value v) {
    int *a = (int *)malloc(sizeof(int) * 1000);
    int i = 0;
    char *s = strtok(v.str, " ");
    while (s != NULL) {
        a[i] = atoi(s);
        i++;
        s = strtok(NULL, " ");
    }
    return a;
}

double *Float64s(Value v) {
    double *a = (double *)malloc(sizeof(double) * 1000);
    int i = 0;
    char *s = strtok(v.str, " ");
    while (s != NULL) {
        a[i] = atof(s);
        i++;
        s = strtok(NULL, " ");
    }
    return a;
}

char *Runes(Value v) {
    return v.str;
}

Values Strings(Values v) {
    Values values;
    values.values = (Value *)malloc(sizeof(Value) * v.len);
    values.len = 0;
    for (int i = 0; i < v.len; i++) {
        values.values[i].str = (char *)malloc(sizeof(char) * 1000);
        values.values[i].len = strlen(v.values[i].str);
        strcpy(values.values[i].str, v.values[i].str);
        values.len++;
    }
    return values;
}

int **Ints(Values v) {
    int **a = (int **)malloc(sizeof(int *) * v.len);
    for (int i = 0; i < v.len; i++) {
        a[i] = Ints(v.values[i]);
    }
    return a;
}

double **Float64s(Values v) {
    double **a = (double **)malloc(sizeof(double *) * v.len);
    for (int i = 0; i < v.len; i++) {
        a[i] = Float64s(v.values[i]);
    }
    return a;
}

char **Runes(Values v) {
    char **a = (char **)malloc(sizeof(char *) * v.len);
    for (int i = 0; i < v.len; i++) {
        a[i] = Runes(v.values[i]);
    }
    return a;
}

void panic(char *s) {
    fprintf(stderr, "panic: %s\n", s);
    exit(1);
}

int main() {
    Run(stdin, stdout);
    return 0;
}

