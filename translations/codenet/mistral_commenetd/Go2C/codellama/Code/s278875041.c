#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    char tmp[100];
    char b[100];
    char ans[100];

    // Reading a string input from the user using scanf()
    scanf("%s", a);

    // Replacing all occurrences of '1' with '0' in the string 'a'
    // and storing the result in the variable 'tmp'
    strcpy(tmp, a);
    strcpy(tmp, str_replace(tmp, "1", "0"));

    // Replacing all occurrences of '9' with '1' in the string 'tmp'
    // and storing the result in the variable 'b'
    strcpy(b, tmp);
    strcpy(b, str_replace(b, "9", "1"));

    // Replacing all occurrences of '0' with '9' in the string 'b'
    // and storing the result in the variable 'ans'
    strcpy(ans, b);
    strcpy(ans, str_replace(ans, "0", "9"));

    // Printing the final answer using printf()
    printf("%s\n", ans);

    return 0;
}

// Function to replace all occurrences of a given substring with another substring
char *str_replace(char *str, char *substr, char *replacement)
{
    char *ptr = str;
    char *tmp = str;
    int substr_len = strlen(substr);
    int replacement_len = strlen(replacement);

    while ((ptr = strstr(ptr, substr)) != NULL)
    {
        strncpy(tmp, ptr, substr_len);
        tmp += substr_len;
        strncpy(tmp, replacement, replacement_len);
        tmp += replacement_len;
        ptr += substr_len;
    }

    strcpy(tmp, ptr);

    return str;
}

// END-OF-CODE