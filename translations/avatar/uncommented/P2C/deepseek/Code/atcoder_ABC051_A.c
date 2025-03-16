#include <stdio.h>

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ',') {
            input[i] = ' ';
        }
    }
    printf("%s", input);
    return 0;
}
