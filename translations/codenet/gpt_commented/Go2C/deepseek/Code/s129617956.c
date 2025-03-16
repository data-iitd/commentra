#include <stdio.h>
#include <math.h>
#include <string.h>

int readInt() {
    int n;
    scanf("%d", &n);
    return n;
}

char* readLine() {
    char buffer[1000000];
    fgets(buffer, sizeof(buffer), stdin);
    // Remove newline character if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
    return strdup(buffer);
}

char** splitString(char* line, const char* delimiter) {
    char** tokens = NULL;
    char* token = strtok(line, delimiter);
    size_t count = 0;

    while (token != NULL) {
        tokens = realloc(tokens, (count + 1) * sizeof(char*));
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, delimiter);
    }

    tokens = realloc(tokens, (count + 1) * sizeof(char*));
    tokens[count] = NULL;
    return tokens;
}

int* parseIntArray(char** tokens) {
    int* array = NULL;
    size_t count = 0;

    while (tokens[count] != NULL) {
        count++;
        array = realloc(array, count * sizeof(int));
        array[count - 1] = atoi(tokens[count - 1]);
    }

    return array;
}

int min(int i, int j) {
    return (i < j) ? i : j;
}

int main() {
    int n = readInt();
    int rt = (int)sqrt(n);
    int minf = 100;

    for (int i = 1; i < rt + 1; i++) {
        if (n % i == 0) {
            int b = n / i;
            int ndigit = 0;

            while (b > 0) {
                b /= 10;
                ndigit++;
            }

            minf = min(minf, ndigit);
        }
    }

    printf("%d\n", minf);

    return 0;
}
