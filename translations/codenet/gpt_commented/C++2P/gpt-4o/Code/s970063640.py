# Declare an integer to hold the number of elements
n = int(input())

# Declare an integer to hold the number of largest elements to sum
a = int(input())

# Initialize a variable to hold the sum of the largest elements
sum = 0

# Declare a list to hold the elements
s = []

# Read the elements into the list from user input
for i in range(n):
    s.append(int(input()))

# Sort the list in non-decreasing order
s.sort()

# Sum the largest 'a' elements from the sorted list
for i in range(n - 1, n - a - 1, -1):
    sum += s[i]

# Output the calculated sum of the largest 'a' elements
print(sum)

# Return 0 to indicate successful completion of the program
# (Not needed in Python, but included for clarity)
# return 0  # This line is not necessary in Python

# <END-OF-CODE>
