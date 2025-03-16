#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1001

char* scanString() {
    char* str = (char*)malloc(MAX_LEN * sizeof(char));
    scanf("%s", str);
    return str;
}

char* scanRunes(char* str) {
    int len = strlen(str);
    char* runes = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        runes[i] = str[i];
    }
    runes[len] = '\0';
    return runes;
}

int scanInt() {
    int num;
    scanf("%d", &num);
    return num;
}

long long scanInt64() {
    long long num;
    scanf("%lld", &num);
    return num;
}

double scanFloat64() {
    double num;
    scanf("%lf", &num);
    return num;
}

void scanInts(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void debug(int a, ...) {
    // Implement debug function if needed
}

int abs(int a) {
    return a < 0 ? -a : a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void printString(char* str) {
    printf("%s\n", str);
}

int main() {
    char* s = scanString();
    char* t = scanString();

    char* ans[MAX_LEN];
    int ans_count = 0;

    for (int i = 0; i <= strlen(s) - strlen(t); i++) {
        int f = 1;
        char* ss = (char*)malloc((strlen(s) + 1) * sizeof(char));
        strcpy(ss, s);

        for (int j = 0; j < strlen(t); j++) {
            if (s[i + j] != t[j] && s[i + j] != '?') {
                f = 0;
                break;
            } else {
                ss[i + j] = t[j];
            }
        }
        if (f) {
            for (int k = 0; k < strlen(ss); k++) {
                if (ss[k] == '?') {
                    ss[k] = 'a';
                }
            }
            ans[ans_count++] = ss;
        }
    }

    if (ans_count == 0) {
        printString("UNRESTORABLE");
    } else {
        for (int i = 0; i < ans_count - 1; i++) {
            for (int j = i + 1; j < ans_count; j++) {
                if (strcmp(ans[i], ans[j]) > 0) {
                    char* temp = ans[i];
                    ans[i] = ans[j];
                    ans[j] = temp;
                }
            }
        }
        printString(ans[0]);
    }

    for (int i = 0; i < ans_count; i++) {
        free(ans[i]);
    }

    free(s);
    free(t);

    return 0;
}
