import sys  # Importing the sys module to read input
input = sys.stdin.readline  # Using readline for faster input
from collections import Counter  # Importing Counter to count occurrences of elements

# Read the number of elements
n = int(input())

# Read the input string, remove the last character (newline), and split it into a list
s = input()[:-1].split()

# Count the occurrences of each element in the list
w = Counter(s)

# Reverse the list to process elements in reverse order
s = s[::-1]

# Initialize variables to track the index of the most frequent element and its value
c, a = -1, 0

# Iterate through each unique element in the count dictionary
for i in w:
    # Check if the current element's count is equal to the maximum count
    if w[i] == max(w.values()):
        # If the index of the current element in the reversed list is greater than the current index
        if s.index(i) > c:
            # Update the most frequent element and its index
            a = i
            c = s.index(i)

# Print the most frequent element that appears last in the original order
print(a)
