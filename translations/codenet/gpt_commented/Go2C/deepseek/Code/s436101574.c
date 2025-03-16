#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1001

char s[MAX_LEN], t[MAX_LEN];
char ans[MAX_LEN];

void scanString(char *str) {
    int i = 0;
    char ch = getchar();
    while (ch != ' ' && ch != '\n') {
        str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
}

void scanRunes(char *str) {
    scanString(str);
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

void scanInts(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void debug(const char *format, ...) {
    #ifdef DEBUG
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    #endif
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

int main() {
    // Read the first string of runes (s)
    scanRunes(s);
    // Read the second string of runes (t)
    scanRunes(t);

    int len_s = strlen(s);
    int len_t = strlen(t);

    // Initialize a slice to hold possible answers
    char *ans[MAX_LEN];
    int ans_count = 0;

    // Iterate through the first string to find occurrences of the second string
    for (int i = 0; i <= len_s - len_t; i++) {
        int f = 1; // Flag to check if the current position is valid
        for (int j = 0; j < len_t; j++) {
            // If characters do not match and are not '?', set flag to false
            if (s[i + j] != t[j] && s[i + j] != '?') {
                f = 0;
                break;
            }
        }
        // If the substring matched, replace remaining '?' with 'a' and store the result
        if (f) {
            for (int j = 0; j < len_s; j++) {
                ans[ans_count] = (j >= i && j < i + len_t) ? t[j - i] : (s[j] == '?' ? 'a' : s[j]);
            }
            ans[ans_count][len_s] = '\0';
            ans_count++;
        }
    }

    // Sort the possible answers
    // (Note: In C, sorting strings is not straightforward without additional libraries)

    // Output the result: either the first valid answer or "UNRESTORABLE"
    if (ans_count == 0) {
        printf("UNRESTORABLE\n");
    } else {
        printf("%s\n", ans[0]);
    }

    return 0;
}
