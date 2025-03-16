class Main:
    # Method to check if a word is a palindrome (case-sensitive)
    @staticmethod
    def is_main(word):
        return Main._is_main(word, False)

    # Method to check if a word is a palindrome (case-insensitive)
    @staticmethod
    def is_main_ignore_case(word):
        return Main._is_main(word, True)

    # Private helper method to check if a word is a palindrome
    @staticmethod
    def _is_main(word, ignore_case):
        # Return false if the input word is None
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
    @staticmethod
    def remove_mains(string):
        # Split the input string into words
        words = string.split(",?\\s+")
        result = []
        # Iterate through each word
        for word in words:
            # If the word is not a palindrome, add it to the result
            if not Main.is_main_ignore_case(word):
                result.append(word)  # Append the non-palindromic word
        return ', '.join(result)  # Return the resulting string

    # Method to remove the nth occurrence of a palindromic word from a string
    @staticmethod
    def remove_nth_main(string, n):
        # Split the input string into words
        words = string.split(",?\\s+")
        counter = 0  # Counter for palindromic words
        result = []
        # Iterate through each word
        for word in words:
            # If the word is a palindrome, increment the counter
            if Main.is_main_ignore_case(word):
                counter += 1
                # Skip adding this word if it's the nth palindrome
                if counter == n:
                    continue
            result.append(word)  # Append the word to the result
        return ', '.join(result)  # Return the resulting string

    # Method to find the longest palindromic substring in a given string
    @staticmethod
    def longest_main_substring(s):
        result = s[0]  # Initialize result with the first character
        # Iterate through each character in the string
        for i in range(len(s)):
            # Check all substrings starting from the current character
            for j in range(len(s) - 1, i + len(result), -1):
                current_string = s[i:j]  # Get the current substring
                # Update result if the current substring is longer and a palindrome
                if len(current_string) > len(result) and Main.is_main(current_string):
                    result = current_string
        return result  # Return the longest palindromic substring found

    # Method to check if the characters of a string can form a palindrome
    @staticmethod
    def can_form_main(s):
        char_count = {}  # Dictionary to track character occurrences
        # Iterate through each character in the string
        for ch in s:
            char_count[ch] = char_count.get(ch, 0) + 1
        # A string can form a palindrome if at most one character has an odd count
        odd_count = sum(1 for count in char_count.values() if count % 2 != 0)
        return odd_count <= 1

# Main method to execute the program
if __name__ == "__main__":
    option = int(input("Enter option (1-5): "))  # Read the user's option
    if option == 1:
        # Check if a word is a palindrome
        word = input("Enter a word: ")
        print("Is Main:", Main.is_main(word))
    elif option == 2:
        # Remove all palindromic words from a string
        string = input("Enter a string: ")
        print("String after removing palindromes:", Main.remove_mains(string))
    elif option == 3:
        # Remove the nth palindromic word from a string
        string2 = input("Enter a string: ")
        n = int(input("Enter n: "))
        print("String after removing nth palindrome:", Main.remove_nth_main(string2, n))
    elif option == 4:
        # Find the longest palindromic substring
        string3 = input("Enter a string: ")
        print("Longest Main Substring:", Main.longest_main_substring(string3))
    elif option == 5:
        # Check if the characters can form a palindrome
        string4 = input("Enter a string: ")
        print("Can form palindrome:", Main.can_form_main(string4))
    else:
        # Handle invalid option
        print("Invalid option")
