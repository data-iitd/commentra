
#include<stdio.h> // Include standard input/output library
#include<string.h> // Include string manipulation library

char str1[100], str2[100], temp[100]; // Declare three character arrays of size 100
int i, j = 0, t; // Declare integer variables i, j, and t

int main() // Start of main function
{
    // Read the first string from the user
    scanf("%s[^\n]", str1);
    printf("First string: %s\n", str1); // Print the first string for verification

    // Read the second string from the user
    scanf("%s[^\n]", str2);
    printf("Second string: %s\n", str2); // Print the second string for verification

    i = strlen(str1); // Get the length of the first string
    t = i - 1; // Set the index variable t to the last index of the first string

    // Check if the lengths of the two strings are equal
    if (strlen(str1) != strlen(str2))
    {
        printf("NO\n"); // If the lengths are not equal, print "NO" and exit
    }
    else
    {
        // Reverse the first string and store it in temp array
        j = 0;
        while (str1[j] != '\0')
        {
            temp[j] = str1[t]; // Swap the characters at the current indices of str1 and temp
            j++;              // Increment j
            t--;              // Decrement t
        }
        // Compare the reversed first string with the second string
        t = 0;
        i = 0;
        while (temp[i] != '\0') // Iterate through the reversed first string
        {
            if (temp[i] == str2[i]) // Check if the corresponding characters are equal
            {
                t++; // Increment the counter if they are equal
            }
            i++; // Increment i
        }

        // Check if all characters are equal and print the result accordingly
        if (strlen(str2) == t)
        {
            printf("YES\n"); // If all characters are equal, print "YES"
        }
        else if (strlen(str2) != t)
        {
            printf("NO\n"); // If any character is different, print "NO"
        }
    }

    return 0; // End of main function
}

