

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000], t[1000];
    scanf("%s", s);
    scanf("%s", t);
    int count_s[26] = {0}, count_t[26] = {0};
    for (int i = 0; s[i]!= '\0'; i++) {
        count_s[s[i] - 'a']++;
    }
    for (int i = 0; t[i]!= '\0'; i++) {
        count_t[t[i] - 'a']++;
    }
    int flag = 0;
    for (int i = 0; i < 26; i++) {
        if (count_s[i]!= count_t[i]) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

