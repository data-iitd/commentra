
import sys

# This class is not thread safe
# (From wikipedia) In computer science, the Boyer–Moore–Horspool algorithm or
# Horspool's algorithm is an algorithm for finding substrings in strings. It
# was published by Nigel Horspool in 1980.
# <a href=https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore%E2%80%93Horspool_algorithm>Wikipedia
# page</a><br>
# <br>

# An explanation:
# The Horspool algorithm is a simplification of the Boyer-Moore algorithm in
# that it uses only one of the two heuristic methods for increasing the number
# of characters shifted when finding a bad match in the text. This method is
# usually called the "bad symbol" or "bad character" shift. The bad symbol
# shift method is classified as an input enhancement method in the theory of
# algorithms. Input enhancement is (from wikipedia) the principle that
# processing a given input to a problem and altering it in a specific way will
# increase runtime efficiency or space efficiency, or both. Both algorithms try
# to match the pattern and text comparing the pattern symbols to the text's
# from right to left.
# <br>
# <br>

# In the bad symbol shift method, a table is created prior to the search,
# called the "bad symbol table". The bad symbol table contains the shift values
# for any symbol in the text and pattern. For these symbols, the value is the
# length of the pattern, if the symbol is not in the first (length - 1) of the
# pattern. Else it is the distance from its rightmost occurrence in the pattern
# to the last symbol of the pattern. In practice, we only calculate the values
# for the ones that exist in the first (length - 1) of the pattern.
# <br>
# <br>

# For more details on the algorithm and the more advanced Boyer-Moore I
# recommend checking out the wikipedia page and professor Anany Levitin's book:
# Introduction To The Design And Analysis Of Algorithms.

def find_first(pattern, text):
    """
    Case sensitive version version of the algorithm

    :param pattern: the pattern to be searched for (needle)
    :param text: the text being searched in (haystack)
    :return: -1 if not found or first index of the pattern in the text
    """
    return first_occurrence(pattern, text, True)

# Fairly standard implementation of the Horspool algorithm. Only the index
# of the last character of the pattern on the text is saved and shifted by
# the appropriate amount when a mismatch is found. The algorithm stops at
# the first match or when the entire text has been exhausted.

def first_occurrence(pattern, text, case_sensitive):
    shift_values = calc_shift_values(pattern)
    comparisons = 0

    if len(pattern) == 0:
        return -1

    text_index = len(pattern) - 1

    while text_index < len(text):
        i = len(pattern) - 1
        while i >= 0:
            comparisons += 1
            pattern_char = pattern[i]
            text_char = text[(text_index + i) - (len(pattern) - 1)]
            if not char_equals(pattern_char, text_char, case_sensitive):
                text_index += get_shift_value(text[text_index])
                break
            i -= 1

        if i == -1:
            return text_index - len(pattern) + 1

    return -1

# Compares the argument characters

def char_equals(c1, c2, case_sensitive):
    return case_sensitive == c1 == c2

# Builds the bad symbol table required to run the algorithm. The method
# starts from the second to last character of the pattern and moves to the
# left. When it meets a new character, it is by definition its rightmost
# occurrence and therefore puts the distance from the current index to the
# index of the last character into the table. If the character is already
# in the table, then it is not a rightmost occurrence, so it continues.

def calc_shift_values(pattern):
    global pattern_length
    pattern_length = len(pattern)
    table = {}

    for i in range(len(pattern) - 2, -1, -1):
        c = pattern[i]
        table.setdefault(c, pattern_length - 1 - i)

    return table

# Helper function that uses the bad symbol shift table to return the
# appropriate shift value for a given character

def get_shift_value(c):
    return shift_values.get(c, pattern_length)

if __name__ == '__main__':
    text = sys.stdin.read()
    pattern = sys.stdin.read()

    # Perform search
    position = find_first(pattern, text)

    # Display results
    if position!= -1:
        print("Pattern found at index: " + str(position))
    else:
        print("Pattern not found.")

