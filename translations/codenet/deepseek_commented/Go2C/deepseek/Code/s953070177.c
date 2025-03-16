#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 500001

// Function to read the next word from the input
char* getNextString() {
    static char line[MAX_LINE_LENGTH];
    static int index = 0;
    static int length = 0;

    if (index >= length) {
        if (fgets(line, sizeof(line), stdin) != NULL) {
            length = strlen(line);
            index = 0;
        } else {
            return NULL;
        }
    }

    char* token = line + index;
    while (index < length && line[index] != ' ' && line[index] != '\n') {
        index++;
    }

    if (index >= length) {
        return token;
    } else {
        line[index] = '\0';
        index++;
        return token;
    }
}

// Function to read the next integer from the input
int getNextInt() {
    char* str = getNextString();
    return str ? atoi(str) : 0;
}

// Function to read the next int64_t from the input
int64_t getNextInt64() {
    char* str = getNextString();
    return str ? strtoll(str, NULL, 10) : 0;
}

// Function to return the absolute value of an integer
int absint(int a) {
    return a < 0 ? -a : a;
}

int main(int argc, char* argv[]) {
    FILE* fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (!fp) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    char buffer[MAX_LINE_LENGTH];
    fgets(buffer, sizeof(buffer), fp);
    int n = atoi(buffer);

    int aa[n + 2];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        aa[i + 1] = getNextInt();
        sum += absint(aa[i + 1] - aa[i]);
    }
    sum += absint(aa[n + 1] - aa[n]);

    for (int i = 1; i < n + 1; i++) {
        int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
        printf("%d\n", ans);
    }

    if (fp != stdin) {
        fclose(fp);
    }

    return EXIT_SUCCESS;
}
