#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compareAsc(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int compareDesc(const void *a, const void *b) {
    return (*(char *)b - *(char *)a);
}

int main() {
    char str1[100], str2[100];
    scanf("%s %s", str1, str2);

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    qsort(str1, len1, sizeof(char), compareAsc);
    qsort(str2, len2, sizeof(char), compareDesc);

    size_t loop = len1 < len2 ? len1 : len2;
    int flag = 0;

    for (size_t i = 0; i < loop; i++) {
        char ch1 = str1[i];
        char ch2 = str2[i];

        if (ch1 == ch2) {
            if (loop == i + 1 && len1 < len2) {
                flag = 1;
                break;
            } else {
                continue;
            }
        } else {
            if (ch2 > ch1) {
                flag = 1;
                break;
            } else {
                break;
            }
        }
    }

    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
