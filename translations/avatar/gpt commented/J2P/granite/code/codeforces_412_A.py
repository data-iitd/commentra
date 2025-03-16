
import sys # Importing the sys module for input and output

# Reading two integers n and k from user input
n, k = map(int, sys.stdin.readline().split())

# Reading a string a from user input
a = sys.stdin.readline().strip()

# Check if k is greater than half of n
if k > n / 2:
    # If true, move to the right until k equals n
    while k < n:
        print("RIGHT") # Output "RIGHT" for each step to the right
        k += 1 # Increment k
else:
    # If false, move to the left until k equals 1
    while k > 1:
        print("LEFT") # Output "LEFT" for each step to the left
        k -= 1 # Decrement k

# If k equals 1, print the characters of the string from left to right
if k == 1:
    for i in range(len(a)):
        print("PRINT", a[i]) # Print the current character
        # If not at the last character, output "RIGHT"
        if i < len(a) - 1:
            print("RIGHT")
else:
    # If k is not 1, print the characters of the string from right to left
    for i in range(len(a) - 1, -1, -1):
        print("PRINT", a[i]) # Print the current character
        # If not at the first character, output "LEFT"
        if i > 0:
            print("LEFT")

# End of code
print("