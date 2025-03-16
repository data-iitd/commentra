

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[1000];
    scanf("%s", s);
    int count[256] = {0};
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        count[s[i]]++;
    }
    int flag = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i]!= 2) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}

