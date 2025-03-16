#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define lambda functions for input handling
int *I(void) {
    int *arr = (int *)malloc(sizeof(int) * 1000000);
    int i = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *fp = fopen("input.txt", "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            arr[i++] = atoi(token);
            token = strtok(NULL, " ");
        }
    }
    fclose(fp);
    return arr;
}

char *IS(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *fp = fopen("input.txt", "r");
    read = getline(&line, &len, fp);
    fclose(fp);
    return line;
}

int IN(void) {
    int i = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *fp = fopen("input.txt", "r");
    read = getline(&line, &len, fp);
    i = atoi(line);
    fclose(fp);
    return i;
}

float IF(void) {
    float f = 0.0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *fp = fopen("input.txt", "r");
    read = getline(&line, &len, fp);
    f = atof(line);
    fclose(fp);
    return f;
}

int main() {
    int n = IN();
    int *l = I();
    int f = 1;
    int c = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (l[i] > c) {
            c++;
        }
    }
    printf("%d\n", c + 1);
    return 0;
}

