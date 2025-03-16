#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    int max_tmp = 0;
    int max = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int flag = 0;
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'T' || s[i] == 'G') {
            max_tmp++;
        } else {
            flag = 1;
        }

        if (i == len - 1) {
            flag = 1;
        }
        if (flag == 1) {
            if (max < max_tmp) {
                max = max_tmp;
            }
            max_tmp = 0;
        }
    }
    printf("%d\n", max);
    return 0;
}
