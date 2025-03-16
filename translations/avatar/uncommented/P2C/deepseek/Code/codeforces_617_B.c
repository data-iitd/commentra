#include <stdio.h>
#include <string.h>

int main() {
    char a[1000];
    scanf("%s", a);
    int count_1 = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == '1') {
            count_1++;
        }
    }
    if (count_1 == 0) {
        printf("0\n");
        return 0;
    }
    char *stripped = strtok(a, "0 ");
    int result = 1;
    while (stripped != NULL) {
        int count_0 = 0;
        for (int i = 0; i < strlen(stripped); i++) {
            if (stripped[i] == '0') {
                count_0++;
            }
        }
        result *= (count_0 + 1);
        stripped = strtok(NULL, "0 ");
    }
    printf("%d\n", result);
    return 0;
}
