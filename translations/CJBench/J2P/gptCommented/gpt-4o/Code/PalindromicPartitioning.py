class Main:
    @staticmethod
    def minimal_partitions(word):
        length = len(word)  # Get the length of the input string
        min_cuts = [0] * length  # List to store the minimum cuts for each substring
        is_palindrome = [[False] * length for _ in range(length)]  # 2D list to check if substrings are palindromes

        # Initialize the is_palindrome list for single character substrings
        for i in range(length):
            is_palindrome[i][i] = True  # A single character is always a palindrome

        # Fill the is_palindrome table for substrings of length 2 and greater
        for sub_len in range(2, length + 1):
            for i in range(length - sub_len + 1):
                j = i + sub_len - 1  # Ending index of the substring
                # Check if the substring from i to j is a palindrome
                if sub_len == 2:
                    is_palindrome[i][j] = (word[i] == word[j])  # Two characters case
                else:
                    is_palindrome[i][j] = (word[i] == word[j]) and is_palindrome[i + 1][j - 1]  # General case

        # Calculate the minimum cuts required for each substring
        for i in range(length):
            if is_palindrome[0][i]:
                min_cuts[i] = 0  # No cuts needed if the whole substring is a palindrome
            else:
                min_cuts[i] = float('inf')  # Initialize to maximum value
                # Check for possible cuts
                for j in range(i):
                    # If the substring from j+1 to i is a palindrome
                    if is_palindrome[j + 1][i] and 1 + min_cuts[j] < min_cuts[i]:
                        min_cuts[i] = 1 + min_cuts[j]  # Update the minimum cuts

        return min_cuts[length - 1]  # Return the minimum cuts for the entire string

# Main execution
if __name__ == "__main__":
    input_string = input()  # Read the input string
    result = Main.minimal_partitions(input_string)  # Calculate the minimum partitions
    print("Minimum number of partitions required:", result)  # Output the result

# <END-OF-CODE>
