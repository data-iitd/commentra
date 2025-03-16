
def minimal_partitions(word):
    len_word = len(word)
    min_cuts = [0] * len_word
    is_palindrome = [[False] * len_word for _ in range(len_word)]

    # Initialize the is_palindrome table for single character substrings
    for i in range(len_word):
        is_palindrome[i][i] = True

    # Fill the is_palindrome table for substrings of length 2 and greater
    for sub_len in range(2, len_word + 1):
        for i in range(len_word - sub_len + 1):
            j = i + sub_len - 1
            # Check if the substring from i to j is a palindrome
            if sub_len == 2:
                is_palindrome[i][j] = (word[i] == word[j])
            else:
                is_palindrome[i][j] = (word[i] == word[j]) and is_palindrome[i + 1][j - 1]

    # Calculate the minimum cuts required for each substring
    for i in range(len_word):
        if is_palindrome[0][i]:
            min_cuts[i] = 0  # No cuts needed if the whole substring is a palindrome
        else:
            min_cuts[i] = float('inf')  # Initialize to maximum value
            # Check for possible cuts
            for j in range(i):
                # If the substring from j+1 to i is a palindrome
                if is_palindrome[j + 1][i] and 1 + min_cuts[j] < min_cuts[i]:
                    min_cuts[i] = 1 + min_cuts[j]  # Update the minimum cuts

    return min_cuts[len_word - 1]  # Return the minimum cuts for the entire string

# Main method to execute the program
if __name__ == "__main__":
    input_string = input("Enter the input string: ")  # Read the input string
    result = minimal_partitions(input_string)  # Calculate the minimum partitions
    print(f"Minimum number of partitions required: {result}")  # Output the result

