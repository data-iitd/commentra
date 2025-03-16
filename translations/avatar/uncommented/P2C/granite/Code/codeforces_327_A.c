
#include <stdio.h>
#include <string.h>
#include <math.h>

int find(char *s, char ch) {
    int i, count = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == ch) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, i, j, maximum = 0;
    char s[100001];
    scanf("%d", &n);
    scanf("%s", s);
    if (find(s, '0') == 0) {
        printf("%d", n - 1);
    } else {
        int indices[n];
        for (i = 0; i < n; i++) {
            if (s[i] == '0') {
                indices[i] = 1;
            } else {
                indices[i] = 0;
            }
        }
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (indices[i] == 1 && indices[j] == 1) {
                    maximum = fmax(maximum, j - i);
                }
            }
        }
        printf("%d", n - 1 - maximum);
    }
    return 0;
}

