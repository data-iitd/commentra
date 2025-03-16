#include <stdio.h>
#include <string.h>

int main() {
    // Creating a Scanner object to read input from the console
    char str[100];
    long k;
    int n;
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter a long integer: ");
    scanf("%ld", &k);
    n = strlen(str);
    for (int i = 0; i < k; i++) {
        if (str[i] == '1') {
            if (i == k - 1) {
                printf("1\n");
                return 0;
            }
        } else {
            printf("%c\n", str[i]);
            return 0;
        }
    }
    return 0;
}
