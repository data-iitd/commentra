
import sys

def minimal_partitions(word):
    len_word = len(word)
    min_cuts = [0] * len_word
    is_palindrome = [[False] * len_word for _ in range(len_word)]

    # Every substring of length 1 is a palindrome
    for i in range(len_word):
        is_palindrome[i][i] = True

    # subLen is substring length. Build the solution in bottom up manner by considering all
    # substrings of length starting from 2 to n.
    for sub_len in range(2, len_word + 1):
        # For substring of length subLen, set different possible starting indexes
        for i in range(len_word - sub_len + 1):
            j = i + sub_len - 1
            # If subLen is 2, then we just need to
            # compare two characters. Else need to
            # check two corner characters and value
            # of P[i+1][j-1]
            if sub_len == 2:
                is_palindrome[i][j] = (word[i] == word[j])
            else:
                is_palindrome[i][j] = (word[i] == word[j]) and is_palindrome[i + 1][j - 1]

    # We find the minimum for each index
    for i in range(len_word):
        if is_palindrome[0][i]:
            min_cuts[i] = 0
        else:
            min_cuts[i] = sys.maxsize
            for j in range(i):
                if is_palindrome[j + 1][i] and 1 + min_cuts[j] < min_cuts[i]:
                    min_cuts[i] = 1 + min_cuts[j]

    # Return the min cut value for complete
    # string. i.e., str[0..n-1]
    return min_cuts[len_word - 1]


def main():
    input_string = sys.stdin.readline().strip()

    result = minimal_partitions(input_string)
    print("Minimum number of partitions required: " + str(result))


if __name__ == "__main__":
    main()

