# Initialize a list of size 3
a = [0] * 3

# Read three integers from the standard input and store them in the list
a[0], a[1], a[2] = map(int, input().split())

# Initialize two variables with zero value
five = 0
seven = 0

# Iterate through the list using a for loop
for i in range(3):
    # Check if the current element of the list is equal to 5
    if a[i] == 5:
        # Increment the variable five by 1
        five += 1
    # Check if the current element of the list is equal to 7
    if a[i] == 7:
        # Increment the variable seven by 1
        seven += 1

# Check if the number of occurrences of 5 is equal to 2 and the number of occurrences of 7 is equal to 1
if five == 2 and seven == 1:
    # Print the string "YES" if the condition is true
    print("YES")
else:
    # Print the string "NO" if the condition is false
    print("NO")

# <END-OF-CODE>
