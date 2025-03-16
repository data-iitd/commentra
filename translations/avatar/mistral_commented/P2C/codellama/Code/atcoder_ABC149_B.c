#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cookies[3];
    int leftOver;
    int takahashi;
    int i;

    // Define a list 'cookies' by using list comprehension
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &cookies[i]);
    }

    // Calculate the difference between the number of cookies given to the first and second child
    leftOver = cookies[0] - cookies[2];

    // Set the 'takahashi' variable to the maximum value between 0 and the 'leftOver' variable
    takahashi = (leftOver > 0) ? leftOver : 0;

    // Print the result using string concatenation
    printf("%d %d", takahashi, (takahashi > 0) ? cookies[1] - takahashi : cookies[1] - abs(leftOver));

    return 0;
}

