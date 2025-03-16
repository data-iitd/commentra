#include<stdio.h>
#include<string.h>

# Declare character arrays to hold two strings and a temporary string for manipulation
str1 = []
str2 = []
temp = []

def main():
    i = 0
    j = 0
    t = 0

    # Read two strings from user input
    str1 = input("Enter the first string: ")
    str2 = input("Enter the second string: ")

    # Get the length of the first string and calculate the last index
    i = len(str1)
    t = i - 1

    # Check if the lengths of the two strings are different
    if(len(str1) != len(str2)):
        # If lengths are different, they cannot be anagrams
        print("NO")
    else:
        # Reverse the first string and store it in the temporary array
        while(str1[j] != '\0'):
            temp[j] = str1[t] # Copy characters from the end of str1 to temp
            j += 1
            t -= 1

        # Null-terminate the reversed string
        temp[j] = '\0' # Ensure the reversed string is properly terminated

        # Reset counters for comparison
        t = 0
        i = 0

        # Compare the reversed string with the second string
        while(temp[i] != '\0'):
            if(temp[i] == str2[i]):
                t += 1 # Count matching characters
            i += 1

        # Check if all characters matched
        if(len(str2) == t):
            # If all characters match, the strings are anagrams
            print("YES")
        else if(len(str2) != t):
            # If not all characters match, they are not anagrams
            print("NO")

if __name__ == "__main__":
    main()

