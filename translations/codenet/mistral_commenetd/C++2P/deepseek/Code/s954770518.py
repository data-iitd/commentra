# Include the necessary libraries for input and output operations
import sys

# Read 10 integers from the user and store them in the list 's'
s = []
for i in range(10):
    s.append(int(sys.stdin.readline()))

# Sort the list 's' in ascending order using the sort function from the built-in library
s.sort()

# Print the 4th, 5th and 6th smallest elements from the sorted list 's'
for i in range(9, 6, -1):
    print(s[i])

# End-of-code comment
print("<END-OF-CODE>")