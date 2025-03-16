
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100000];
    int map[26];
    int oddCount = 0;

    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        int ch = str[i] - 'a';
        if (map[ch] > 0) {
            map[ch]++;
        } else {
            map[ch] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (map[i] % 2!= 0) {
            oddCount++;
        }
    }

    if (oddCount <= 1 || oddCount % 2!= 0) {
        printf("First\n");
    } else {
        printf("Second\n");
    }

    return 0;
}

