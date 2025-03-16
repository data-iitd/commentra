
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int count = 0;
    int counter[1000] = {0};

    if (strlen(s) == 0) {
        return 0;
    }
    counter[0] = 0;
    char *li[1000];
    char *token = strtok(s, "");

    int i = 0;
    while (token!= NULL) {
        li[i] = token;
        token = strtok(NULL, "");
        i++;
    }

    for (int j = 0; j < i; j++) {
        if (strcmp(li[j], "A") == 0 || strcmp(li[j], "C") == 0 || strcmp(li[j], "G") == 0 || strcmp(li[j], "T") == 0) {
            count++;
        } else {
            counter[j] = count;
            count = 0;
        }
    }

    counter[i] = count;
    qsort(counter, i + 1, sizeof(int), compare);
    printf("%d\n", counter[i]);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

