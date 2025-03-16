#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char *s, char ch) {
    int *indices = (int *)malloc(strlen(s) * sizeof(int));
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ch) {
            indices[count++] = i;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);

    if (strchr(s, '0') == NULL) {
        printf("%d\n", n - 1);
    } else {
        int indices[n];
        int index_count = find(s, '0');
        if (index_count == 1) {
            printf("%d\n", n);
        } else {
            int maximum = 0;
            for (int i = 0; i < index_count; i++) {
                indices[i] = strchr(s, '0') - s;
            }
            for (int i = 0; i < index_count; i++) {
                for (int j = i + 1; j < index_count; j++) {
                    int distance = 2 + 2 * (abs(indices[i] - indices[j]) - 1) - (abs(indices[i] - indices[j]) - 1);
                    if (distance > maximum) {
                        maximum = distance;
                    }
                }
            }
            printf("%d\n", count_ones(s) + maximum);
        }
    }
    return 0;
}

int count_ones(char *s) {
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '1') {
            count++;
        }
    }
    return count;
}
