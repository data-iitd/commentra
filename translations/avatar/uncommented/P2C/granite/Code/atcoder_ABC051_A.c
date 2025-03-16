
#include <stdio.h>

int main() {
    char input[100];
    fgets(input, 100, stdin);
    printf("%s", input);
    return 0;
}
// 