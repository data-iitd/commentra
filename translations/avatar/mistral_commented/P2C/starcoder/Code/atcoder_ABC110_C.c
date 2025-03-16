#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the occurrences of each character in string's'
// and store the result in a dictionary
void count(char *s, int *d)
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        d[s[i]]++;
    }
}

// Function to compare the sorted lists of occurrences of characters in strings's' and 't'
// If they are equal, then the strings have the same frequency distribution of characters
// and thus are identical, so return 'Yes'
// Otherwise, return 'No'
char *run(char *s, char *t)
{
    int i, d1[256], d2[256];
    char *res;

    // Counting the occurrences of each character in string's'
    count(s, d1);

    // Counting the occurrences of each character in string 't'
    count(t, d2);

    // Comparing the sorted lists of occurrences of characters in strings's' and 't'
    for (i = 0; i < 256; i++)
    {
        if (d1[i]!= d2[i])
        {
            res = "No";
            break;
        }
    }

    // If the loop is not broken, then the strings have the same frequency distribution of characters
    // and thus are identical, so return 'Yes'
    if (i == 256)
    {
        res = "Yes";
    }

    return res;
}

// Driver function
int main()
{
    char s[1000], t[1000];
    scanf("%s", s);
    scanf("%s", t);
    printf("%s\n", run(s, t));
    return 0;
}

