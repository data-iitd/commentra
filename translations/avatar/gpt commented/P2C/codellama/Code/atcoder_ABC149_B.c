#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cookies[3];
    int leftOver;
    int takahashi;
    char input[100];
    char *token;
    int i = 0;

    // Read a line of input, split it into parts, and convert each part to an integer
    fgets(input, 100, stdin);
    token = strtok(input, " ");
    while (token != NULL)
    {
        cookies[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    // Calculate the leftover cookies after taking some from the third type
    leftOver = cookies[0] - cookies[2];

    // Determine the number of cookies Takahashi can take, ensuring it's not negative
    takahashi = max(0, leftOver);

    // Print the number of cookies Takahashi can take, and the remaining cookies of the second type
    // If Takahashi can take cookies, print the second type's count; otherwise, calculate the remaining
    printf("%d %s", takahashi, (takahashi > 0 ? "%d" : "%d"), cookies[1], (takahashi > 0 ? cookies[1] : max(0, cookies[1] - abs(leftOver))));

    return 0;
}

