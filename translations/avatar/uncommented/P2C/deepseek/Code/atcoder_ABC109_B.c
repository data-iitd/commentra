#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 10

int main() {
    int n;
    char s[MAX_WORDS][MAX_LEN];
    int count[MAX_WORDS] = {0};
    char temp[MAX_LEN];
    int i, j;
    int flag = 1;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    for (i = 0; i < n; i++) {
        count[i]++;
        for (j = 0; j < n; j++) {
            if (i != j && strcmp(s[i], s[j]) == 0) {
                flag = 0;
                break;
            }
        }
        if (i > 0 && strcmp(&s[i-1][strlen(s[i-1])-1], s[i][0]) != 0) {
            flag = 0;
        }
        if (flag == 0) {
            break;
        }
    }

    printf("%s\n", flag ? "Yes" : "No");

    return 0;
}
