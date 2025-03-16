
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char input_string[1000];
    char modified_string[1000];

    scanf("%s", input_string);

    for (int i = 0; i < strlen(input_string); i++)
    {
        if (input_string[i] == ',')
        {
            modified_string[i] ='';
        }
        else
        {
            modified_string[i] = input_string[i];
        }
    }

    printf("%s", modified_string);

    return 0;
}

