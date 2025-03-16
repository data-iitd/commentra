#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int reverse_compare(const void *a, const void *b) {
    return (*(char *)b - *(char *)a);
}

int main() {
    char str1[1000], str2[1000];
    scanf("%s %s", str1, str2);

    qsort(str1, strlen(str1), sizeof(char), compare);
    qsort(str2, strlen(str2), sizeof(char), reverse_compare);

    int loop = strlen(str1) > strlen(str2) ? strlen(str2) : strlen(str1);
    int flag = 0;

    for (int i = 0; loop > i; i++) {
        char ch1 = str1[i];
        char ch2 = str2[i];

        if (ch1 == ch2) {
            if (loop == i + 1 && strlen(str1) < strlen(str2)) {
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

