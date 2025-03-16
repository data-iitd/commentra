# Import the necessary libraries
import sys

# Read the input word from standard input
W = input().strip()

# Sort the characters in the string W in ascending order
W = ''.join(sorted(W))

# Initialize an iterator to point to the first character in the sorted string W
itr = 0

# Loop through the sorted string W
while itr < len(W) - 1:
    # Check if the current character and the next character in the string are the same
    if W[itr] != W[itr + 1]:
        # If they are not the same, print "No" and exit
        print("No")
        sys.exit(0)
    itr += 1

# If the loop completes without finding any pair of non-identical characters, print "Yes"
print("Yes")

# End of code
# <END-OF-CODE>
