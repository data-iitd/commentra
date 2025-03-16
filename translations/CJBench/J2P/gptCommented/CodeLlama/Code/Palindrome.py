
# Method to check if a word is a palindrome (case-sensitive)
def is_main(word):
    return is_main(word, False)

# Method to check if a word is a palindrome (case-insensitive)
def is_main_ignore_case(word):
    return is_main(word, True)

# Private helper method to check if a word is a palindrome
def is_main(word, ignore_case):
    # Return false if the input word is null
    if word is None:
        return False
    # Convert the word to lowercase if case-insensitivity is required
    if ignore_case:
        word = word.lower()
    # Check for palindrome by comparing characters from both ends
    for i in range(len(word) // 2):
        if word[i] != word[len(word) - 1 - i]:
            return False  # Return false if characters do not match
    return True  # Return true if the word is a palindrome

# Method to remove all palindromic words from a given string
def remove_mains(string):
    # Split the input string into words
    words = string.split(",?\\s+")
    result = ""
    # Iterate through each word
    for word in words:
        # If the word is not a palindrome, add it to the result
        if not is_main_ignore_case(word):
            if result != "":
                result += ", "  # Add a comma if result is not empty
            result += word  # Append the non-palindromic word
    return result  # Return the resulting string

# Method to remove the nth occurrence of a palindromic word from a string
def remove_nth_main(string, n):
    # Split the input string into words
    words = string.split(",?\\s+")
    counter = 0  # Counter for palindromic words
    result = ""
    # Iterate through each word
    for word in words:
        # If the word is a palindrome, increment the counter
        if is_main_ignore_case(word):
            counter += 1
            # Skip adding this word if it's the nth palindrome
            if counter == n:
                continue
        if result != "":
            result += ", "  # Add a comma if result is not empty
        result += word  # Append the word to the result
    return result  # Return the resulting string

# Method to find the longest palindromic substring in a given string
def longest_main_substring(str):
    result = str[0]  # Initialize result with the first character
    # Iterate through each character in the string
    for i in range(len(str)):
        # Check all substrings starting from the current character
        for j in range(len(str) - 1, i + len(result), -1):
            current_string = str[i:j]  # Get the current substring
            # Update result if the current substring is longer and a palindrome
            if len(current_string) > len(result) and is_main(current_string):
                result = current_string
    return result  # Return the longest palindromic substring found

# Method to check if the characters of a string can form a palindrome
def can_form_main(str):
    set = set()  # Set to track character occurrences
    # Iterate through each character in the string
    for ch in str:
        # Add character to set if not present, otherwise remove it
        if ch not in set:
            set.add(ch)
        else:
            set.remove(ch)
    # A string can form a palindrome if at most one character has an odd count
    return len(set) <= 1

# Main method to execute the program
def main():
    option = int(input("Enter your option: "))
    if option == 1:
        # Check if a word is a palindrome
        word = input("Enter a word: ")
        print("Is Main:", is_main(word))
    elif option == 2:
        # Remove all palindromic words from a string
        string = input("Enter a string: ")
        print("String after removing palindromes:", remove_mains(string))
    elif option == 3:
        # Remove the nth palindromic word from a string
        string = input("Enter a string: ")
        n = int(input("Enter the nth palindrome to remove: "))
        print("String after removing nth palindrome:", remove_nth_main(string, n))
    elif option == 4:
        # Find the longest palindromic substring
        string = input("Enter a string: ")
        print("Longest Main Substring:", longest_main_substring(string))
    elif option == 5:
        # Check if the characters can form a palindrome
        string = input("Enter a string: ")
        print("Can form palindrome:", can_form_main(string))
    else:
        # Handle invalid option
        print("Invalid option")

if __name__ == "__main__":
    main()

