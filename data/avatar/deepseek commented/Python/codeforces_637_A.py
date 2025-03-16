import sys
input = sys.stdin.readline
from collections import Counter

# Read the integer n and the list of strings s from standard input
n = int(input())
s = input()[:-1].split()

# Create a Counter object w from the list s
w = Counter(s)

# Reverse the list s
s = s[::-1]

# Initialize two variables c and a to -1 and 0 respectively
c, a = -1, 0

# Iterate over the items in the Counter object w
for i in w:
    # Check if the count of the item is equal to the maximum count in the Counter object
    if w[i] == max(w.values()):
        # Check if the index of the item in the reversed list s is greater than the current value of c
        if s.index(i) > c:
            # Update the value of a to the current item and update the value of c to the index of the current item in the reversed list s
            a = i
            c = s.index(i)

# Print the value of a
print(a)