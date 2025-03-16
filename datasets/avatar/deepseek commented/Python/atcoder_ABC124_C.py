
import collections

# Take a string input from the user and store it in the variable `s`
s = list(input())

# Create a Counter object `even` that counts the occurrences of characters at even indices in the string `s`
even = collections.Counter(s[0::2])

# Create a Counter object `odd` that counts the occurrences of characters at odd indices in the string `s`
odd = collections.Counter(s[1::2])

# Print the minimum of two possible outcomes:
# 1. The number of characters that need to be flipped to make all even characters '0' and the number of characters that need to be flipped to make all even characters '1', or vice versa.
print(min(len(s) - (even["0"] + odd["1"]), len(s) - (even["1"] + odd["0"])))


