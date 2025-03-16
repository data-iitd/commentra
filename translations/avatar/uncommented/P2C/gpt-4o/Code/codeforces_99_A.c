#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    scanf("%s", input);

    char *l = strtok(input, ".");
    char *p = strtok(NULL, ".");

    char s[100];
    strcpy(s, l);
    
    int i = p[0] - '0'; // Convert first character of p to integer

    if (s[strlen(s) - 1] == '9') {
        printf("GOTO Vasilisa.\n");
    } else if (s[strlen(s) - 1] != '9' && i < 5) {
        printf("%s\n", s);
    } else {
        int num = atoi(s);
        num += 1;
        printf("%d\n", num);
    }

    return 0;
}

// <END-OF-CODE>
