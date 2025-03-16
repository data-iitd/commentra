
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FastReader {
    FILE *br;
    char *str;
    char *token;
    int len;
};

struct FastReader *new_FastReader() {
    struct FastReader *obj = (struct FastReader *)malloc(sizeof(struct FastReader));
    obj->br = fopen("/dev/stdin", "r");
    obj->str = (char *)malloc(1024 * sizeof(char));
    obj->token = (char *)malloc(1024 * sizeof(char));
    obj->len = 0;
    return obj;
}

char *next(struct FastReader *obj) {
    if (obj->len == 0) {
        fgets(obj->str, 1024, obj->br);
        obj->len = strlen(obj->str);
        obj->str[obj->len - 1] = '\0';
        obj->token = strtok(obj->str, " ");
    } else {
        obj->token = strtok(NULL, " ");
    }
    return obj->token;
}

int nextInt(struct FastReader *obj) {
    return atoi(next(obj));
}

long nextLong(struct FastReader *obj) {
    return atol(next(obj));
}

double nextDouble(struct FastReader *obj) {
    return atof(next(obj));
}

char *nextLine(struct FastReader *obj) {
    char *str = (char *)malloc(1024 * sizeof(char));
    fgets(str, 1024, obj->br);
    return str;
}

int reverse(int n) {
    if (n < 10)
        return n * 10;
    int t = n, r = 0;
    while (t > 0) {
        r = (r * 10) + t % 10;
        t = t / 10;
    }
    return r;
}

int main() {
    struct FastReader *sc = new_FastReader();
    int n = nextInt(sc); // Read the first integer
    int m = nextInt(sc); // Read the second integer
    int t = reverse(m); // Reverse the second integer
    printf("%d\n", t + n); // Print the sum of the reversed integer and the first integer
    return 0;
}

