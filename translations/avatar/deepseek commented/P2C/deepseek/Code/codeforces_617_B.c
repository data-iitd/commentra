#include <stdio.h>
#include <string.h>

int main() {
    char a[1000]; // Assuming the input won't exceed 1000 characters
    scanf("%s", a); // Read the input into the array 'a'

    int count_1 = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == '1') {
            count_1++;
        }
    }

    if (count_1 == 0) {
        printf("0\n");
    } else {
        int product = 1;
        char *token = strtok(a, "0 ");
        while (token != NULL) {
            product *= (strspn(token, "0") + 1);
            token = strtok(NULL, "0 ");
        }
        printf("%d\n", product);
    }

    return 0;
}
