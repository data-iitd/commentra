#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 500001

char* getNextString() {
    static char buffer[MAX_INPUT_SIZE];
    fgets(buffer, MAX_INPUT_SIZE, stdin);
    // Remove newline character if present
    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}

int getNextInt() {
    return atoi(getNextString());
}

long long getNextInt64() {
    return atoll(getNextString());
}

unsigned long long getNextUint64() {
    return strtoull(getNextString(), NULL, 10);
}

double getNextFloat64() {
    return atof(getNextString());
}

void solve() {
    int k = getNextInt();
    int x = getNextInt();

    char* ans = "No";
    if (k * 500 >= x) {
        ans = "Yes";
    }
    printf("%s\n", ans);
}

int main() {
    FILE* fp = stdin;
    FILE* wfp = stdout;
    int cnt = 0;

    if (getenv("MASPY") && strcmp(getenv("MASPY"), "ますピ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
        if (!fp) {
            perror("Error opening file");
            return 1;
        }
        cnt = 2;
    }
    if (getenv("MASPYPY") && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
        if (!wfp) {
            perror("Error creating file");
            return 1;
        }
    }

    for (int i = 0; i < cnt; i++) {
        printf("-----------------------------------\n");
        solve();
    }

    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}
