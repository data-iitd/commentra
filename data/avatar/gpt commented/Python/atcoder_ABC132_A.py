# Take input string from the user
S = input()

# Import the Counter class from the collections module to count occurrences of characters
from collections import Counter

# Create a Counter object to count the frequency of each character in the string
c = Counter(S)

# Create a set of unique characters from the input string
Sa = set(list(S))

# Check if the number of unique characters is not equal to 2
if len(Sa) != 2:
    # If there are not exactly 2 unique characters, print "No" and exit
    print("No")
    exit()

# Iterate over each unique character in the set
for i in Sa:
    # Check if the count of the current character is not equal to 2
    if c[i] != 2:
        # If any character does not appear exactly twice, print "No" and exit
        print("No")
        exit()

# If both conditions are satisfied, print "Yes"
print("Yes")
