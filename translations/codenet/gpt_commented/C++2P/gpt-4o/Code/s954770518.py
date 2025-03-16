# Declare an array to hold 10 integers
s = []

# Input 10 integers from the user
for i in range(10):
    num = int(input())
    s.append(num)

# Sort the array of integers in ascending order
s.sort()

# Print the three largest integers from the sorted array
for i in range(9, 6, -1):
    print(s[i])

# Indicate that the program ended successfully
# <END-OF-CODE>
