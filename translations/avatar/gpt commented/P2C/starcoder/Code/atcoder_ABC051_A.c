#include <stdio.h>
#include <stdlib.h>

int main()
{
    char user_input[100];
    char modified_input[100];

    scanf("%s", user_input);

    for (int i = 0; i < strlen(user_input); i++)
    {
        if (user_input[i] == ',')
        {
            modified_input[i] ='';
        }
        else
        {
            modified_input[i] = user_input[i];
        }
    }

    printf("%s", modified_input);

    return 0;
}
