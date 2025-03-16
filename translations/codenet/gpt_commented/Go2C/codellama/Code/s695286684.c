#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    printf("The string after replacing all occurrences of 2017 with 2018 is: %s\n", strstr(s, "2017"));
    return 0;
}

