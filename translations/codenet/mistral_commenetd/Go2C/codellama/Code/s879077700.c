
#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    char ans[100] = "Good";
    int i;

    // Read user input using scanf() function and store it in variable 'a'
    scanf("%s", a);

    // Loop through each character in the string 'a' for 3 times
    for (i = 0; i < 3; i++)
    {
        // Check if the current character is same as next character
        if (a[i] == a[i+1])
        {
            // Update the value of 'ans' if current and next character are same
            strcpy(ans, "Bad");
        }
    }

    // Print the final value of 'ans'
    printf("%s\n", ans);

    return 0;
}

