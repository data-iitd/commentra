#include <stdio.h>
#include <string.h>

// Define long long type for large integers
typedef long long ll;

int main()
{
    // Declare variables for input and processing
    ll a;
<<<<<<< HEAD
    char z[100001]; // Assuming a maximum length for the input string
=======
    char z[100]; // Assuming a maximum length for the input string
>>>>>>> 98c87cb78a (data updated)

    // Read the input string
    scanf("%s", z);
    
    // Get the size of the input string
    a = strlen(z);
    
    // Check for consecutive identical characters in the string
    for (int i = 0; i < a - 1; i++)
    {
        // If two consecutive characters are the same, print "Bad" and exit
        if (z[i] == z[i + 1])
        {
            printf("Bad\n");
            return 0;
        }
    }
    
    // If no consecutive identical characters were found, print "Good"
    printf("Good\n");
    
    return 0;
}

// <END-OF-CODE>
