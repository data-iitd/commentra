#include<iostream> 
#include<vector> 
#include<string> 
#include<algorithm> 
using namespace std; 

int main()
{
    # Declare a string variable to store the input
    s = input()

    # Loop through each character from 'a' to 'z'
    for i in range(ord('a'), ord('z') + 1):
        # Initialize a counter to track occurrences of the current character
        a = 0

        # Loop through each character in the input string
        for j in range(len(s)):
            # Check if the current character matches the character being checked
            if s[j] == chr(i):
                # Increment the counter if a match is found
                a += 1

        # If the character was not found in the input string
        if a == 0:
            # Output the first missing character and exit the loop
            print(chr(i))
            break

        # If we reach the end of the alphabet and all characters are present
        if i == ord('z'):
            # Output "None" if no characters are missing
            print("None")
            break

# 