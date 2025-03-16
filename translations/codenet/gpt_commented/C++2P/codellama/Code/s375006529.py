#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    # Declare a string variable to hold the input
    s = ""
    
    # Read the input string from the user
    cin >> s
    
    # Get the size of the input string
    n = len(s)
    
    # Initialize an array to count occurrences of each character (a-z)
    v = [0] * 26
    
    # Count the frequency of each character in the string
    for i in range(n):
        v[ord(s[i]) - ord('a')] += 1 # Increment the count for the corresponding character
    
    # Assume the answer is "Yes" initially
    ans = "Yes"
    
    # Check if each character's count is even
    for i in range(26):
        if v[i] % 2 != 0: # If any character has an odd count
            ans = "No" # Set answer to "No"
            break # Exit the loop early as we found an odd count
    
    # Output the result
    print(ans)
}

