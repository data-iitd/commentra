#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* find(const char* s, char ch, int* count) {
    int length = strlen(s);
    int* indices = (int*)malloc(length * sizeof(int));
    *count = 0;

    for (int i = 0; i < length; i++) {
        if (s[i] == ch) {
            indices[(*count)++] = i;
        }
    }
    return indices;
}

int main() {
    int n;
    scanf("%d", &n);
    char* s = (char*)malloc((n + 1) * sizeof(char));
    scanf("%s", s);

    if (strchr(s, '0') == NULL) {
        printf("%d\n", n - 1);
    } else {
        int count;
        int* indices = find(s, '0', &count);
        if (count == 1) {
            printf("%d\n", n);
        } else {
            int maximum = 0;
            for (int i = 0; i < count; i++) {
                for (int j = i + 1; j < count; j++) {
                    int abs_diff = abs(indices[i] - indices[j]);
                    maximum = (maximum > (2 + 2 * (abs(i - j) - 1) - (abs_diff - 1))) ? maximum : (2 + 2 * (abs(i - j) - 1) - (abs_diff - 1));
                }
            }
            printf("%d\n", (int)(strlen(s) - count) + maximum);
        }
        free(indices);
    }
    free(s);
    return 0;
}

// <END-OF-CODE>
