#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100]; // Assuming a maximum length of 100 for the input string
    int sum;

    while(1)
    {
        scanf("%s", str);
        if(strcmp(str, "0") == 0) break;
        sum = 0;
        for(int i = 0; i < strlen(str); i++)
        {
            char tmp[2]; // Temporary string to hold a single character
            tmp[0] = str[i];
            tmp[1] = '\0'; // Null-terminate the string
            int num = atoi(tmp);
            sum += num;
        }
        
        printf("%d\n", sum);
    }
    return 0;
}

// <END-OF-CODE>
