
#include <stdio.h>
#include <string.h>

int main() {
    char user_input[100];
    printf("Enter a string: ");
    fgets(user_input, 100, stdin);

    char *token = strtok(user_input, ",");
    while (token!= NULL) {
        printf("%s ", token);
        token = strtok(NULL, ",");
    }

    return 0;
}
// END-OF-CODE