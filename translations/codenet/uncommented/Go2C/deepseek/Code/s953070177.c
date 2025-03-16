#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 500001

char line[MAX_LINE_LENGTH];
int bufferIndex = 0;

void getNextString() {
    int i = 0;
    while (line[bufferIndex] != ' ' && line[bufferIndex] != '\n') {
        line[i++] = line[bufferIndex++];
    }
    line[i] = '\0';
    bufferIndex++;
}

int getNextInt() {
    getNextString();
    return atoi(line);
}

long long getNextInt64() {
    getNextString();
    return atoll(line);
}

void getScanner(FILE *fp) {
    fgets(line, MAX_LINE_LENGTH, fp);
    bufferIndex = 0;
}

int main() {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    getScanner(fp);

    int n = getNextInt();

    int aa[n + 2];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        getScanner(fp);
        aa[i + 1] = getNextInt();
        sum += abs(aa[i + 1] - aa[i]);
    }
    getScanner(fp);
    sum += abs(aa[n + 1] - aa[n]);

    for (int i = 1; i < n + 1; i++) {
        int ans = sum - abs(aa[i + 1] - aa[i]) - abs(aa[i] - aa[i - 1]) + abs(aa[i + 1] - aa[i - 1]);
        printf("%d\n", ans);
    }

    return 0;
}

int abs(int a) {
    return a < 0 ? -a : a;
}
