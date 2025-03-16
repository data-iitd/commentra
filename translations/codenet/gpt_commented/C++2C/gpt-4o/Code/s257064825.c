#include <stdio.h>
#include <string.h>

<<<<<<< HEAD
int main() {
    // Declare a string to hold the input
    char str[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
=======
// Define 'int' as 'long long int' for larger integer support
typedef long long int int64;

int main()
{
    // Optimize input/output operations
    // In C, we don't have the same optimizations as in C++, but we can use scanf and printf for I/O.
    
    // Declare a string to hold the input
    char str[100]; // Assuming the input string will not exceed 99 characters
    
>>>>>>> 98c87cb78a (data updated)
    // Read the input string from the user
    scanf("%s", str);
    
    // Initialize a variable to hold the sum of digits
<<<<<<< HEAD
    long long int sum = 0;
    
    // Iterate through each character in the string
    for(int i = 0; i < strlen(str); i++) {
=======
    int64 sum = 0;
    
    // Iterate through each character in the string
    for(int i = 0; i < strlen(str); i++)
    {
>>>>>>> 98c87cb78a (data updated)
        // Convert character to integer and add to sum
        sum += (str[i] - '0'); // '0' is the character representation of zero
    }
    
    // Check if the sum of digits is divisible by 9
<<<<<<< HEAD
    if(sum % 9 == 0) {
        // If divisible, print "Yes"
        printf("Yes\n");
    } else {
=======
    if(sum % 9 == 0)
    {
        // If divisible, print "Yes"
        printf("Yes\n");
    }
    else
    {
>>>>>>> 98c87cb78a (data updated)
        // If not divisible, print "No"
        printf("No\n");
    }
    
    return 0;
}

// <END-OF-CODE>
