def minimal_partitions(word):
    length = len(word)
    min_cuts = [0] * length
    is_palindrome = [[False] * length for _ in range(length)]
    
    # Initialize single character palindromes
    for i in range(length):
        is_palindrome[i][i] = True
    
    # Calculate all palindromes of length 2 to len
    for sub_len in range(2, length + 1):
        for i in range(length - sub_len + 1):
            j = i + sub_len - 1
            if sub_len == 2:
                is_palindrome[i][j] = (word[i] == word[j])
            else:
                is_palindrome[i][j] = (word[i] == word[j]) and is_palindrome[i + 1][j - 1]
    
    # Calculate the minimal cuts required
    for i in range(length):
        if is_palindrome[0][i]:
            min_cuts[i] = 0
        else:
            min_cuts[i] = float('inf')
            for j in range(i):
                if is_palindrome[j + 1][i] and 1 + min_cuts[j] < min_cuts[i]:
                    min_cuts[i] = 1 + min_cuts[j]
    
    return min_cuts[length - 1]

# Main method to read input string and print the minimal number of partitions required.
if __name__ == "__main__":
    import sys
    input_string = sys.stdin.readline().strip()
    result = minimal_partitions(input_string)
    print("Minimum number of partitions required:", result)
