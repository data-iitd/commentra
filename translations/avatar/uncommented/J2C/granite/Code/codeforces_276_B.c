
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char str[100001];
    scanf("%s", str);
    int map[256] = {0};
    int oddCount = 0;
    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];
        map[ch]++;
    }
    for (int i = 0; i < 256; i++) {
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
//END-OF-CODE