#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Take an input from the user and assign it to the variable 'n'
    char n[100];
    scanf("%s", n);

    // Initialize a list 'a' with some strings representing numbers
    char a[5][100] = {"10", "100", "1000", "10000", "100000"};

    // Convert each element of the input 'n' to an integer using the 'atoi' function
    // and then sum up all the integers using the 'sum' function and assign the result to the variable 'new'
    int new = 0;
    for (int i = 0; i < 5; i++)
    {
        new += atoi(a[i]);
    }

    // Check if the input 'n' is present in the list 'a'
    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(n, a[i]) == 0)
        {
            flag = 1;
            break;
        }
    }

    // If the input 'n' is present in the list 'a', then print the number 10
    if (flag == 1)
    {
        printf("10\n");
    }
    // If the input 'n' is not present in the list 'a', then print the value of the variable 'new'
    else
    {
        printf("%d\n", new);
    }

    return 0;
}
