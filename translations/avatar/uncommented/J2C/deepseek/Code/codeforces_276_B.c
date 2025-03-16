#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1000];
    int map[128] = {0};
    int oddCount = 0;

    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character

    for (int i = 0; i < strlen(str); i++) {
        map[(int)str[i]]++;
    }

    for (int i = 0; i < 128; i++) {
        if (map[i] % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount <= 1 || oddCount % 2 != 0) {
        printf("First\n");
    } else {
        printf("Second\n");
    }

    return 0;
}
