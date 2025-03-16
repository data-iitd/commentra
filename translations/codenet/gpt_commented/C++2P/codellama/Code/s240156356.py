#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    # Declare two strings to hold the input
    str1, str2 = "", ""
    
    # Read two strings from the standard input
    str1, str2 = input(), input()

    # Sort the first string in ascending order
    str1 = sorted(str1)
    
    # Sort the second string in descending order
    str2 = sorted(str2, reverse=True)

    # Determine the length of the shorter string for the loop
    loop = len(str1) if len(str1) < len(str2) else len(str2)
    
    # Initialize a flag to track if the condition is met
    flag = False

    # Loop through the characters of both strings up to the length of the shorter one
    for i in range(loop):
        ch1 = str1[i] # Get the character from the first string
        ch2 = str2[i] # Get the character from the second string

        # Check if the characters are equal
        if ch1 == ch2:
            # If we are at the last character of the shorter string and str1 is shorter
            if loop == i + 1 and len(str1) < len(str2):
                flag = True # Set the flag to true
                break # Exit the loop
            else:
                continue # Continue to the next iteration
        else:
            # If the character from str2 is greater than that from str1
            if ch2 > ch1:
                flag = True # Set the flag to true
                break # Exit the loop
            else:
                break # Exit the loop if ch1 is greater

    # Output the result based on the flag's value
    if flag:
        print("Yes") # Condition met
    else:
        print("No") # Condition not met
}

