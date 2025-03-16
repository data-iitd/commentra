
#include <stdio.h>

int main() {
    char input[100];
    fgets(input, 100, stdin);
    char *token = strtok(input, " ");
    int result = 0;
    while (token!= NULL) {
        result++;
        if (strcmp(token, "0") == 0) {
            break;
        }
        token = strtok(NULL, " ");
    }
    printf("%d\n", result);
    return 0;
}
// END-OF-CODE