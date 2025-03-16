import collections  # Import the collections module to use Counter for counting elements

# Read input string and convert it into a list of characters
s = list(input())

# Count the occurrences of '0' and '1' at even indices
even = collections.Counter(s[0::2])

# Count the occurrences of '0' and '1' at odd indices
odd = collections.Counter(s[1::2])

# Calculate the minimum number of changes needed to make the string alternate
# Option 1: Change all even indexed '0's to '1's and odd indexed '1's to '0's
# Option 2: Change all even indexed '1's to '0's and odd indexed '0's to '1's
# Print the minimum of the two options
print(min(len(s) - (even["0"] + odd["1"]), len(s) - (even["1"] + odd["0"])))
