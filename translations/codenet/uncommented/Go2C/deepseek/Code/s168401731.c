#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 500001

char* getNextString() {
    static char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        char* pos = strchr(buffer, '\n');
        if (pos != NULL) {
            *pos = '\0';
        }
        char* token = strtok(buffer, " ");
        return token;
    }
    return NULL;
}

int getNextInt() {
    char* str = getNextString();
    return atoi(str);
}

long long getNextInt64() {
    char* str = getNextString();
    return atoll(str);
}

unsigned long long getNextUint64() {
    char* str = getNextString();
    return strtoull(str, NULL, 10);
}

double getNextFloat64() {
    char* str = getNextString();
    return atof(str);
}

int main() {
    FILE* fp = stdin;
    FILE* wfp = stdout;

    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, fp);
    int n = atoi(buffer);

    char ans[5] = "second";
    for (int i = 0; i < n; i++) {
        int a = getNextInt();
        if (a % 2 == 1) {
            strcpy(ans, "first");
            break;
        }
    }
    fprintf(wfp, "%s\n", ans);
    fclose(fp);
    fclose(wfp);
    return 0;
}
