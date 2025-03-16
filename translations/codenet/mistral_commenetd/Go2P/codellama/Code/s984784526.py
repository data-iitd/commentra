
# Initialize an array of size 3 with type int
a = [0, 0, 0]

# Read three integers from the standard input and store them in the array
a[0], a[1], a[2] = map(int, input().split())

# Initialize two variables with zero value
five, seven = 0, 0

# Iterate through the array using a for loop
for i in range(3):
    # Check if the current element of the array is equal to 5
    if a[i] == 5:
        # Increment the variable five by 1
        five += 1
    # Check if the current element of the array is equal to 7
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

# END-OF-CODE