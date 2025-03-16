
import sys

def minimal_partitions(word):
    len_word = len(word)
    min_cuts = [0] * len_word
    is_palindrome = [[False] * len_word for _ in range(len_word)]
    for i in range(len_word):
        is_palindrome[i][i] = True
    for sub_len in range(2, len_word + 1):
        for i in range(len_word - sub_len + 1):
            j = i + sub_len - 1
            if sub_len == 2:
                is_palindrome[i][j] = (word[i] == word[j])
            else:
                is_palindrome[i][j] = (word[i] == word[j]) and is_palindrome[i + 1][j - 1]
    for i in range(len_word):
        if is_palindrome[0][i]:
            min_cuts[i] = 0
        else:
            min_cuts[i] = sys.maxsize
            for j in range(i):
                if is_palindrome[j + 1][i] and 1 + min_cuts[j] < min_cuts[i]:
                    min_cuts[i] = 1 + min_cuts[j]
    return min_cuts[len_word - 1]


def main():
    input_string = sys.stdin.readline().strip()
    result = minimal_partitions(input_string)
    print("Minimum number of partitions required:", result)


if __name__ == "__main__":
    main()

