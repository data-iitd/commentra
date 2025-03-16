
# <START-OF-CODE>

# Read the input string from the standard input.
str = input()

# Initialize max and cnt to keep track of the maximum length of consecutive 'A', 'C', 'G', or 'T' characters and the current length of such a sequence, respectively.
max = 0
cnt = 0

# Iterate over each character in the string.
for sc in str:
    # Check if the character is one of 'A', 'C', 'G', or 'T'.
    if sc == 'A' or sc == 'C' or sc == 'G' or sc == 'T':
        # If it is, increment the cnt variable.
        cnt += 1
    else:
        # If not, reset cnt to 0.
        cnt = 0
    # After each character, update max to be the maximum of max and cnt.
    max = max if max > cnt else cnt

# Print the value of max to the standard output.
print(max)

# 