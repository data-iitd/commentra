

def minimal_partitions(word):
    len_word = len(word)
    min_cuts = [0] * len_word
    is_palindrome = [[False] * len_word for _ in range(len_word)]
    # Initialize single character palindromes
    for i in range(len_word):
        is_palindrome[i][i] = True
    # Calculate all palindromes of length 2 to len
    for sub_len in range(2, len_word + 1):
        for i in range(len_word - sub_len + 1):
            j = i + sub_len - 1
            if sub_len == 2:
                is_palindrome[i][j] = (word[i] == word[j])
            else:
                is_palindrome[i][j] = (word[i] == word[j]) and is_palindrome[i + 1][j - 1]
    # Calculate the minimal cuts required
    for i in range(len_word):
        if is_palindrome[0][i]:
            min_cuts[i] = 0
        else:
            min_cuts[i] = float('inf')
            for j in range(i):
                if is_palindrome[j + 1][i] and 1 + min_cuts[j] < min_cuts[i]:
                    min_cuts[i] = 1 + min_cuts[j]
    return min_cuts[len_word - 1]

# Main method to read input string and print the minimal number of partitions required
input_string = input("Enter the input string: ")
result = minimal_partitions(input_string)
print("Minimum number of partitions required:", result)

