#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char str[MAX_STRING_LENGTH];
    int count;
} StringCount;

int main() {
    int n;
    scanf("%d", &n);

    StringCount strings[n];
    int string_count = 0;
    char f[4] = "Yes";

    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i].str);
        strings[i].count = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(strings[i].str, strings[j].str) == 0) {
                strings[i].count++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (strings[i].count > 1) {
            strcpy(f, "No");
            break;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (strcmp(strings[i].str[strlen(strings[i].str) - 1], strings[i + 1].str[0]) != 0) {
            strcpy(f, "No");
            break;
        }
    }

    printf("%s\n", f);

    return 0;
}
