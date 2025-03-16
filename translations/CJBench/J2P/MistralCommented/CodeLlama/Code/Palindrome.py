
import re

def is_main(word):
    # Check if word is None, return False if it is
    if word is None:
        return False
    
    # If ignoreCase flag is True, convert word to lowercase
    if ignoreCase:
        word = word.lower()
    
    # Check if the first half of the word is equal to the second half
    for i in range(len(word) // 2):
        # Compare corresponding characters of the first and last halves
        if word[i] != word[-i - 1]:
            # If they are not equal, return False
            return False
    
    # If all checks pass, return True
    return True

def is_main_ignore_case(word):
    # Call is_main method with ignoreCase flag set to True
    return is_main(word, True)

def remove_mains(string):
    # Initialize an empty string to store the result
    result = ""
    
    # Split the string into words using a regular expression
    words = re.split(",?\s+", string)
    
    # Iterate through each word
    for word in words:
        # If the word is not a main word, add it to the result string
        if not is_main_ignore_case(word):
            # Add a comma and a space before the word, if it's not the first one
            if result:
                result += ", "
            # Append the word to the result string
            result += word
    
    # Return the result as a string
    return result

def remove_nth_main(string, n):
    # Initialize an empty string to store the result
    result = ""
    
    # Split the string into words using a regular expression
    words = re.split(",?\s+", string)
    
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
            result += ", "
        
        # Append the word to the result string
        result += word
    
    # Return the result as a string
    return result

def longest_main_substring(str):
    # Initialize an empty string to store the current result
    result = str[0]
    
    # Iterate through each substring of the given string, starting from a length of 1
    for i in range(len(str)):
        for j in range(len(str) - 1, i + len(result), -1):
            # Get the current substring
            current_string = str[i:j]
            
            # Check if the current substring is a main word (palindrome) and longer than the current result
            if len(current_string) > len(result) and is_main(current_string):
                # Update the result if the current substring is longer
                result = current_string
    
    # Return the result as a string
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
    
    # Return True if the set contains only one character, False otherwise
    return len(set) <= 1

# Main method to read user input and call the appropriate methods based on the given option
def main():
    # Initialize a Scanner object to read user input
    sc = input()
    
    # Read the user's option
    option = int(sc)
    
    # Read the user's input for option 2, 3, and 4
    sc = input()
    
    # Switch on the user's option and call the appropriate method
    if option == 1:
        # Read a word from the user and print whether it's a main word or not
        word = sc
        print("Is Main: " + str(is_main(word)))
    elif option == 2:
        # Read a string from the user and print the string after removing all main words
        string = sc
        print("String after removing palindromes: " + remove_mains(string))
    elif option == 3:
        # Read a string and an integer from the user and print the string after removing the nth main word
        string, n = sc.split()
        n = int(n)
        print("String after removing nth palindrome: " + remove_nth_main(string, n))
    elif option == 4:
        # Read a string from the user and print the longest main substring (palindrome)
        string = sc
        print("Longest Main Substring: " + longest_main_substring(string))
    elif option == 5:
        # Read a string from the user and print whether it can form a main word (palindrome) or not
        string = sc
        print("Can form palindrome: " + str(can_form_main(string)))
    else:
        # Print an error message if the user enters an invalid option
        print("Invalid option")

# Call the main method
main()

