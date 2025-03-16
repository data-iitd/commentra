#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int list[n];
    char input[1000];
    scanf("%s", input);
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            list[count++] = (input[i-1] - '0') % 2;
        }
    }
    list[count] = (input[count] - '0') % 2;

    if (sum(list, n) == 1) {
        for (int i = 0; i < n; i++) {
            if (list[i] == 1) {
                printf("%d\n", i + 1);
                break;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (list[i] == 0) {
                printf("%d\n", i + 1);
                break;
            }
        }
    }
    return 0;
}
