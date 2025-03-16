#include <stdio.h>
#include <string.h>

int main() {
    char s[100001]; // Assuming the maximum length of the string is 100000
    scanf("%s", s);

    int max_tmp = 0;
    int max = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        int flag = 0;
        switch (s[i]) {
            case 'A':
            case 'C':
            case 'T':
            case 'G':
                max_tmp++;
                break;
            default:
                flag = 1;
                break;
        }

        if (i == length - 1) {
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

// <END-OF-CODE>
