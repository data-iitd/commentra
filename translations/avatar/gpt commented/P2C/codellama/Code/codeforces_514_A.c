#include <stdio.h>

int main()
{
    // Get user input
    char ip[100];
    scanf("%s", ip);

    // Initialize an empty string to store the transformed number
    char st[100] = "";

    // Check if the input length is not equal to 1
    if (strlen(ip) != 1)
    {
        // If the first character is '9', keep it and remove it from the input
        if (ip[0] == '9')
        {
            st[0] = '9';  // Start the output string with '9'
            ip[0] = '\0';  // Remove the first character from the input
        }

        // Iterate through each character in the remaining input
        for (int i = 0; i < strlen(ip); i++)
        {
            // If the digit is greater than 4, calculate its complement to 9
            if (ip[i] > '4')
            {
                int n = 9 - ip[i];  // Calculate the complement
                st[i] = n + '0';  // Append the complement to the output string
            }
            else
            {
                // If the digit is 4 or less, keep it unchanged
                st[i] = ip[i];  // Append the original digit to the output string
            }
        }
    }
    else
    {
        // If the input length is 1, simply assign it to the output
        strcpy(st, ip);
    }

    // Print the final transformed number as an integer
    printf("%d", atoi(st));

    return 0;
}

