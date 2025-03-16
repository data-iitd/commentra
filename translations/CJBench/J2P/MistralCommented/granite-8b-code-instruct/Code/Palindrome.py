

import re

def is_main(word):
    # Check if word is null, return false if it is
    if word is None:
        return False
    
    # If ignoreCase flag is true, convert word to lowercase
    if ignoreCase:
        word = word.lower()
    
    # Check if the first half of the word is equal to the second half
    for i in range(len(word) // 2):
        # Compare corresponding characters of the first and last halves
        if word[i]!= word[len(word) - 1 - i]:
            # If they are not equal, return false
            return False
    
    # If all checks pass, return true
    return True

def is_main_ignore_case(word):
    # Call is_main method with ignoreCase flag set to true
    return is_main(word, True)

def remove_mains(string):
    # Initialize an empty list to store the result
    result = []
    
    # Split the string into words using a regular expression
    words = re.split(",?\\s+", string)
    
    # Iterate through each word
    for word in words:
        # If the word is not a main word, add it to the result list
        if not is_main_ignore_case(word):
            result.append(word)
    
    # Return the result as a string
    return ", ".join(result)

def remove_nth_main(string, n):
    # Initialize an empty list to store the result
    result = []
    
    # Split the string into words using a regular expression
    words = re.split(",?\\s+", string)
    
    # Initialize a counter variable
    counter = 0
    
    # Iterate through each word
    for word in words:
        # If the word is a main word, increment the counter
        if is_main_ignore_case(word):
            counter += 1
            
            # If the counter equals the given n, skip this word and continue with the next one
            if counter == n:
                continue
    
    # Add a comma and a space before the word, if it's not the first one
    if result:
        result.append(", ")
    
    # Append the word to the result list
    result.append(word)
    
    # Return the result as a string
    return ", ".join(result)

def longest_main_substring(str):
    # Initialize an empty String to store the current result
    result = str[0]
    
    # Iterate through each substring of the given string, starting from a length of 1
    for i in range(len(str)):
        for j in range(len(str) - 1, i + len(result) + 1, -1):
            # Get the current substring
            current_string = str[i:j]
            
            # Check if the current substring is a main word (palindrome) and longer than the current result
            if len(current_string) > len(result) and is_main(current_string):
                # Update the result if the current substring is longer
                result = current_string
    
    # Return the result as a String
    return result

def can_form_main(str):
    # Initialize an empty set to store unique characters
    set = set()
    
    # Iterate through each character in the given string
    for ch in str:
        # Add the character to the set, removing it if it's already present
        if ch not in set:
            set.add(ch)
        else:
            set.remove(ch)
    
    # Return true if the set contains only one character, false otherwise
    return len(set) <= 1

# Main method to read user input and call the appropriate methods based on the given option
if __name__ == "__main__":
    # Read the user's option
    option = int(input())
    
    # Read the user's input for option 2, 3, and 4
    input()
    
    # Switch on the user's option and call the appropriate method
    if option == 1:
        # Read a word from the user and print whether it's a main word or not
        word = input()
        print("Is Main: " + str(is_main(word)))
    elif option == 2:
        # Read a string from the user and print the string after removing all main words
        string = input()
        print("String after removing palindromes: " + remove_mains(string))
    elif option == 3:
        # Read a string and an integer from the user and print the string after removing the nth main word
        string2 = input()
        n = int(input())
        print("String after removing nth palindrome: " + remove_nth_main(string2, n))
    elif option == 4:
        # Read a string from the user and print the longest main substring (palindrome)
        string3 = input()
        print("Longest Main Substring: " + longest_main_substring(string3))
    elif option == 5:
        # Read a string from the user and print whether it can form a main word (palindrome) or not
        string4 = input()
        print("Can form palindrome: " + str(can_form_main(string4)))
    else:
        # Print an error message if the user enters an invalid option
        print("Invalid option")

