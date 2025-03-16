

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Declare empty strings s1, s2, and s3 for user input
    string s1, s2, s3;

    // Read user input for strings s1, s2, and s3
    s1 = get_string("s1: ");
    s2 = get_string("s2: ");
    s3 = get_string("s3: ");

    // Declare slices s1s, s2s, and s3s to store individual characters of strings s1, s2, and s3 respectively
    string s1s[strlen(s1)];
    string s2s[strlen(s2)];
    string s3s[strlen(s3)];

    // Populate slices s1s, s2s, and s3s with individual characters of strings s1, s2, and s3 respectively
    for (int i = 0; i < strlen(s1); i++)
    {
        s1s[i] = s1[i];
    }
    for (int i = 0; i < strlen(s2); i++)
    {
        s2s[i] = s2[i];
    }
    for (int i = 0; i < strlen(s3); i++)
    {
        s3s[i] = s3[i];
    }

    // Print the concatenated uppercase first character of each string
    printf("%c%c%c\n", toupper(s1s[0]), toupper(s2s[0]), toupper(s3s[0]));

    return 0;
}
