#include <stdio.h>
#include <string.h>

int main()
{
    char user_input[100];
    char modified_input[100];

    printf("Enter a string: ");
    scanf("%s", user_input);

    strcpy(modified_input, user_input);
    strcpy(modified_input, strtok(modified_input, ","));

    printf("Modified string: %s\n", modified_input);

    return 0;
}
