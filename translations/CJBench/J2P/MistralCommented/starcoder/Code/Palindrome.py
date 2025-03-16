
import re

# Method to check if a given word is a main word (palindrome)
def isMain(word):
    # Check if word is null, return false if it is
    if word == None:
        return False
    
    # If ignoreCase flag is true, convert word to lowercase
    if ignoreCase:
        word = word.lower()
    
    # Check if the first half of the word is equal to the second half
    for i in range(0, len(word) // 2):
        # Compare corresponding characters of the first and last halves
        if word[i]!= word[len(word) - 1 - i]:
            # If they are not equal, return false
            return False
    
    # If all checks pass, return true
    return True

# Method to check if a given word is a main word (palindrome) ignoring case
def isMainIgnoreCase(word):
    # Call isMain method with ignoreCase flag set to true
    return isMain(word, True)

# Method to remove all main words (palindromes) from a given string
def removeMains(string):
    # Initialize an empty StringBuilder to store the result
    result = ""
    
    # Split the string into words using a regular expression
    words = re.split(",?\\s+", string)
    
    # Iterate through each word
    for word in words:
        # If the word is not a main word, add it to the result StringBuilder
        if not isMainIgnoreCase(word):
            # Add a comma and a space before the word, if it's not the first one
            if result!= "":
                result += ", "
            # Append the word to the result StringBuilder
            result += word
    
    # Return the result as a String
    return result

# Method to remove the nth main word (palindrome) from a given string
def removeNthMain(string, n):
    # Initialize an empty StringBuilder to store the result
    result = ""
    
    # Split the string into words using a regular expression
    words = re.split(",?\\s+", string)
    
    # Initialize a counter variable
    counter = 0
    
    # Iterate through each word
    for word in words:
        # If the word is a main word, increment the counter
        if isMainIgnoreCase(word):
            counter += 1
            
            # If the counter equals the given n, skip this word and continue with the next one
            if counter == n:
                continue
        
        # Add a comma and a space before the word, if it's not the first one
        if result!= "":
            result += ", "
        
        # Append the word to the result StringBuilder
        result += word
    
    # Return the result as a String
    return result

# Method to find the longest main substring (palindrome) in a given string
def longestMainSubstring(str):
    # Initialize an empty String to store the current result
    result = str[0:1]
    
    # Iterate through each substring of the given string, starting from a length of 1
    for i in range(0, len(str)):
        for j in range(len(str) - 1, i + result.length() + 1, -1):
            # Get the current substring
            currentString = str[i:j]
            
            # Check if the current substring is a main word (palindrome) and longer than the current result
            if currentString.length() > result.length() and isMain(currentString):
                # Update the result if the current substring is longer
                result = currentString
    
    # Return the result as a String
    return result

# Method to check if a given string can form a main word (palindrome)
def canFormMain(str):
    # Initialize an empty HashSet to store unique characters
    set = set()
    
    # Iterate through each character in the given string
    for ch in str:
        # Add the character to the HashSet, removing it if it's already present
        if ch not in set:
            set.add(ch)
        else:
            set.remove(ch)
    
    # Return true if the HashSet contains only one character, false otherwise
    return len(set) <= 1

# Main method to read user input and call the appropriate methods based on the given option
def main():
    # Initialize a Scanner object to read user input
    sc = Scanner(System.in)
    
    # Read the user's option
    option = sc.nextInt()
    
    # Read the user's input for option 2, 3, and 4
    sc.nextLine()
    
    # Switch on the user's option and call the appropriate method
    if option == 1:
        # Read a word from the user and print whether it's a main word or not
        word = sc.nextLine()
        print("Is Main: " + str(isMain(word)))
    elif option == 2:
        # Read a string from the user and print the string after removing all main words
        string = sc.nextLine()
        print("String after removing palindromes: " + removeMains(string))
    elif option == 3:
        # Read a string and an integer from the user and print the string after removing the nth main word
        string2 = sc.nextLine()
        n = sc.nextInt()
        print("String after removing nth palindrome: " + removeNthMain(string2, n))
    elif option == 4:
        # Read a string from the user and print the longest main substring (palindrome)
        string3 = sc.nextLine()
        print("Longest Main Substring: " + longestMainSubstring(string3))
    elif option == 5:
        # Read a string from the user and print whether it can form a main word (palindrome) or not
        string4 = sc.nextLine()
        print("Can form palindrome: " + str(canFormMain(string4)))
    else:
        # Print an error message if the user enters an invalid option
        print("Invalid option")
    
    # Close the Scanner object
    sc.close()

# Call the main method
main()

