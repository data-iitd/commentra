#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to count the occurrences of each element in the list
int count(char *s, int n) {
    int i, j, k, c;
    char *t;
    t = (char *)malloc(n * sizeof(char));
    for (i = 0; i < n; i++) {
        c = 0;
        for (j = 0; j < n; j++) {
            if (s[i] == s[j]) {
                c++;
            }
        }
        t[i] = c;
    }
    return t;
}

// Function to find the most frequent element that appears last in the original order
int main() {
    int n, i, j, k, c, a;
    char *s, *t;
    scanf("%d", &n);
    s = (char *)malloc(n * sizeof(char));
    for (i = 0; i < n; i++) {
        scanf("%c", &s[i]);
    }
    t = count(s, n);
    a = 0;
    c = -1;
    for (i = 0; i < n; i++) {
        if (t[i] > c) {
            c = t[i];
            a = i;
        }
    }
    for (i = 0; i < n; i++) {
        if (t[i] == c) {
            for (j = 0; j < n; j++) {
                if (s[j] == s[a]) {
                    k = j;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (k == i) {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}

