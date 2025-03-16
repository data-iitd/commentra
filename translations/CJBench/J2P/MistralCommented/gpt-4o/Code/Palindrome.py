import re

# Method to check if a given word is a main word (palindrome)
def is_main(word, ignore_case=False):
    # Check if word is None, return False if it is
    if word is None:
        return False
    
    # If ignore_case flag is true, convert word to lowercase
    if ignore_case:
        word = word.lower()
    
    # Check if the first half of the word is equal to the second half
    for i in range(len(word) // 2):
        # Compare corresponding characters of the first and last halves
        if word[i] != word[len(word) - 1 - i]:
            # If they are not equal, return False
            return False
    
    # If all checks pass, return True
    return True

# Method to check if a given word is a main word (palindrome) ignoring case
def is_main_ignore_case(word):
    # Call is_main method with ignore_case flag set to True
    return is_main(word, True)

# Method to remove all main words (palindromes) from a given string
def remove_mains(string):
    # Initialize an empty list to store the result
    result = []
    
    # Split the string into words using a regular expression
    words = re.split(r',?\s+', string)
    
    # Iterate through each word
    for word in words:
        # If the word is not a main word, add it to the result list
        if not is_main_ignore_case(word):
            result.append(word)
    
    # Return the result as a string
    return ', '.join(result)

# Method to remove the nth main word (palindrome) from a given string
def remove_nth_main(string, n):
    # Initialize an empty list to store the result
    result = []
    
    # Split the string into words using a regular expression
    words = re.split(r',?\s+', string)
    
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
        
        # Append the word to the result list
        result.append(word)
    
    # Return the result as a string
    return ', '.join(result)

# Method to find the longest main substring (palindrome) in a given string
def longest_main_substring(s):
    # Initialize an empty string to store the current result
    result = s[0] if s else ""
    
    # Iterate through each substring of the given string
    for i in range(len(s)):
        for j in range(len(s) - 1, i + len(result), -1):
            # Get the current substring
            current_string = s[i:j]
            
            # Check if the current substring is a main word (palindrome) and longer than the current result
            if len(current_string) > len(result) and is_main(current_string):
                # Update the result if the current substring is longer
                result = current_string
    
    # Return the result as a string
    return result

# Method to check if a given string can form a main word (palindrome)
def can_form_main(s):
    # Initialize an empty set to store unique characters
    char_set = set()
    
    # Iterate through each character in the given string
    for ch in s:
        # Add the character to the set, removing it if it's already present
        if ch in char_set:
            char_set.remove(ch)
        else:
            char_set.add(ch)
    
    # Return True if the set contains only one character, False otherwise
    return len(char_set) <= 1

# Main method to read user input and call the appropriate methods based on the given option
def main():
    # Read the user's option
    option = int(input())
    
    # Read the user's input for option 2, 3, and 4
    input()  # Consume the newline after the option
    
    # Switch on the user's option and call the appropriate method
    if option == 1:
        # Read a word from the user and print whether it's a main word or not
        word = input()
        print("Is Main:", is_main(word))
    elif option == 2:
        # Read a string from the user and print the string after removing all main words
        string = input()
        print("String after removing palindromes:", remove_mains(string))
    elif option == 3:
        # Read a string and an integer from the user and print the string after removing the nth main word
        string2 = input()
        n = int(input())
        print("String after removing nth palindrome:", remove_nth_main(string2, n))
    elif option == 4:
        # Read a string from the user and print the longest main substring (palindrome)
        string3 = input()
        print("Longest Main Substring:", longest_main_substring(string3))
    elif option == 5:
        # Read a string from the user and print whether it can form a main word (palindrome) or not
        string4 = input()
        print("Can form palindrome:", can_form_main(string4))
    else:
        # Print an error message if the user enters an invalid option
        print("Invalid option")

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
