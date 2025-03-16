import sys; # Importing the sys module for reading input from the user

# Reading two integers n and k from user input
n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

# Reading a string a from user input
a = sys.stdin.readline()

# Check if k is greater than half of n
if (k > n / 2):
    # If true, move to the right until k equals n
    while (k < n):
        print("RIGHT") # Output "RIGHT" for each step to the right
        k += 1 # Increment k
else:
    # If false, move to the left until k equals 1
    while (k > 1):
        print("LEFT") # Output "LEFT" for each step to the left
        k -= 1 # Decrement k

# If k equals 1, print the characters of the string from left to right
if (k == 1):
    for i in range(0, a.length()):
        print("PRINT " + a.charAt(i)) # Print the current character
        # If not at the last character, output "RIGHT"
        if ((i + 1) < a.length()):
            print("RIGHT")
else:
    # If k is not 1, print the characters of the string from right to left
    for i in range(a.length() - 1, -1, -1):
        print("PRINT " + a.charAt(i)) # Print the current character
        # If not at the first character, output "LEFT"
        if ((i - 1) >= 0):
            print("LEFT")

# 