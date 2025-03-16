
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    fgets(input, 1000, stdin);
    char *token = strtok(input, " ");
    int result = 0;
    while (token!= NULL) {
        if (strcmp(token, "0")!= 0) {
            result++;
        } else {
            break;
        }
        token = strtok(NULL, " ");
    }
    printf("%d\n", result);
    return 0;
}
