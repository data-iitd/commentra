class Main:
    @staticmethod
    def minimal_partitions(word):
        length = len(word)  # length of the given word
        min_cuts = [0] * length  # array to store the minimum number of cuts required for each substring

        is_palindrome = [[False] * length for _ in range(length)]  # 2D boolean array to check if a substring is a palindrome or not

        # Initialize the diagonal of the is_palindrome matrix with True values
        for i in range(length):
            is_palindrome[i][i] = True

        # Fill the rest of the is_palindrome matrix
        for sub_len in range(2, length + 1):
            for i in range(length - sub_len + 1):
                j = i + sub_len - 1

                # Base case for substring of length 2
                if sub_len == 2:
                    is_palindrome[i][j] = (word[i] == word[j])
                else:
                    # Recursive case for substrings of length greater than 2
                    is_palindrome[i][j] = (word[i] == word[j]) and is_palindrome[i + 1][j - 1]

        # Calculate the minimum number of cuts required for each substring
        for i in range(length):
            if is_palindrome[0][i]:
                min_cuts[i] = 0  # If the substring is a palindrome, no cuts are required
            else:
                min_cuts[i] = float('inf')  # If the substring is not a palindrome, initialize the minimum number of cuts as infinity
                for j in range(i):
                    if is_palindrome[j + 1][i] and 1 + min_cuts[j] < min_cuts[i]:
                        min_cuts[i] = 1 + min_cuts[j]  # Update the minimum number of cuts if a palindrome substring is found before the current substring

        # Return the minimum number of cuts required for the entire word
        return min_cuts[length - 1]

if __name__ == "__main__":
    input_string = input()  # Read a line of input from the console
    result = Main.minimal_partitions(input_string)  # Calculate the minimum number of partitions required for the input string
    print("Minimum number of partitions required:", result)  # Print the result to the console

# <END-OF-CODE>
