#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initialize an empty list 's' to store input elements
    char *s = (char *)malloc(100 * sizeof(char));
    scanf("%s", s);

    // Initialize an empty dictionary 'dt' to store the count of each unique element
    int dt[100];
    memset(dt, 0, sizeof(dt));

    // Set a boolean variable 'x' to True to indicate whether there is an odd count element in the list
    int x = 1;

    // Iterate through each element 'i' in the list 's'
    for (int i = 0; i < strlen(s); i++)
    {
        // Check if the element 'i' already exists as a key in the dictionary 'dt'
        if (dt[s[i]] != 0)
        {
            // If it does, increment its value by 1
            dt[s[i]] += 1;
        }
        else
        {
            // If not, add it as a new key with a value of 1
            dt[s[i]] = 1;
        }
    }

    // Initialize a counter 'cnt' to 0 and set 'x' to True
    int cnt = 0;
    x = 1;

    // Iterate through each key-value pair ('key', 'value') in the dictionary 'dt'
    for (int key = 0; key < 100; key++)
    {
        // If the value is odd and 'cnt' is less than 1, increment 'cnt' by 1
        if (dt[key] % 2 != 0 && cnt < 1)
        {
            cnt += 1;
        }
        // If the value is odd and 'cnt' is already greater than or equal to 1, set 'x' to False and break the loop
        else if (dt[key] % 2 != 0 && cnt >= 1)
        {
            x = 0;
            break;
        }
    }

    // After the loop, check the value of 'x'
    if (x)
    {
        // If it is True, print "First"
        printf("First\n");
    }
    else if (!x && strlen(s) % 2 == 0)
    {
        // If it is False and the length of the list 's' is even, print "Second"
        printf("Second\n");
    }
    else if (!x && strlen(s) % 2 != 0)
    {
        // If it is False and the length of the list 's' is odd, print "First"
        printf("First\n");
    }

    return 0;
}

