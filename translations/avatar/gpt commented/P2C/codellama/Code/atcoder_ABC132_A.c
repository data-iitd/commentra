#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to count the frequency of each character in a string
void count_frequency(char *str, int *count)
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        count[str[i]]++;
    }
}

// Function to check if the number of unique characters is not equal to 2
int check_unique_characters(char *str)
{
    int i, j;
    for (i = 0; i < strlen(str); i++)
    {
        for (j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j])
            {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if the count of each character is not equal to 2
int check_count(char *str, int *count)
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if (count[str[i]] != 2)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[100];
    int count[256] = {0};

    // Take input string from the user
    scanf("%s", str);

    // Check if the number of unique characters is not equal to 2
    if (check_unique_characters(str) == 0)
    {
        // If there are not exactly 2 unique characters, print "No" and exit
        printf("No\n");
        return 0;
    }

    // Count the frequency of each character in the string
    count_frequency(str, count);

    // Check if the count of each character is not equal to 2
    if (check_count(str, count) == 0)
    {
        // If any character does not appear exactly twice, print "No" and exit
        printf("No\n");
        return 0;
    }

    // If both conditions are satisfied, print "Yes"
    printf("Yes\n");

    return 0;
}

