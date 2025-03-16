# Import necessary modules
from collections import Counter

# Read input string from the user
W = input()

# Count the occurrences of each character in the string
char_count = Counter(W)

# Check if all characters have even counts
for count in char_count.values():
    if count % 2 != 0:
        # If any character has an odd count, print "No" and exit
        print("No")
        break
else:
    # If all characters have even counts, print "Yes"
    print("Yes")

# <END-OF-CODE>
