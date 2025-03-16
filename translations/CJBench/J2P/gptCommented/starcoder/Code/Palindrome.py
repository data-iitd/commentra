import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

def isMain(word, ignoreCase=False):
    # Return false if the input word is null
    if word == None:
        return False
    # Convert the word to lowercase if case-insensitivity is required
    if ignoreCase:
        word = word.lower()
    # Check for palindrome by comparing characters from both ends
    for i in range(0, len(word) / 2):
        if word[i]!= word[len(word) - 1 - i]:
            return False # Return false if characters do not match
    return True # Return true if the word is a palindrome

def removeMains(string):
    # Split the input string into words
    words = string.split(",?\\s+")
    result = ""
    # Iterate through each word
    for word in words:
        # If the word is not a palindrome, add it to the result
        if not isMain(word, True):
            if result!= "":
                result += ", " # Add a comma if result is not empty
            result += word # Append the non-palindromic word
    return result # Return the resulting string

def removeNthMain(string, n):
    # Split the input string into words
    words = string.split(",?\\s+")
    counter = 0 # Counter for palindromic words
    result = ""
    # Iterate through each word
    for word in words:
        # If the word is a palindrome, increment the counter
        if isMain(word, True):
            counter += 1
            # Skip adding this word if it's the nth palindrome
            if counter == n:
                continue
        if result!= "":
            result += ", " # Add a comma if result is not empty
        result += word # Append the word to the result
    return result # Return the resulting string

def longestMainSubstring(str):
    result = str[0:1] # Initialize result with the first character
    # Iterate through each character in the string
    for i in range(0, len(str)):
        # Check all substrings starting from the current character
        for j in range(len(str) - 1, i + len(result) + 1, -1):
            currentString = str[i:j] # Get the current substring
            # Update result if the current substring is longer and a palindrome
            if len(currentString) > len(result) and isMain(currentString):
                result = currentString
    return result # Return the longest palindromic substring found

def canFormMain(str):
    set = set() # Set to track character occurrences
    # Iterate through each character in the string
    for ch in str:
        # Add character to set if not present, otherwise remove it
        if ch not in set:
            set.add(ch)
        else:
            set.remove(ch)
    # A string can form a palindrome if at most one character has an odd count
    return len(set) <= 1

def main():
    sc = Scanner(System.in) # Create a Scanner object for input
    option = sc.nextInt() # Read the user's option
    sc.nextLine() # Consume the newline character
    if option == 1:
        # Check if a word is a palindrome
        word = sc.nextLine()
        print("Is Main: " + isMain(word))
    elif option == 2:
        # Remove all palindromic words from a string
        string = sc.nextLine()
        print("String after removing palindromes: " + removeMains(string))
    elif option == 3:
        # Remove the nth palindromic word from a string
        string2 = sc.nextLine()
        n = sc.nextInt()
        print("String after removing nth palindrome: " + removeNthMain(string2, n))
    elif option == 4:
        # Find the longest palindromic substring
        string3 = sc.nextLine()
        print("Longest Main Substring: " + longestMainSubstring(string3))
    elif option == 5:
        # Check if the characters can form a palindrome
        string4 = sc.nextLine()
        print("Can form palindrome: " + canFormMain(string4))
    else:
        # Handle invalid option
        print("Invalid option")
    sc.close() # Close the Scanner

if __name__ == "__main__":
    main()

