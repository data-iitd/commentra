# Ask the user for the number of elements in the list
n = int(input())

# Initialize an empty list to store the integers
l = []

# Iterate n times and append each integer to the list
for i in range(n):
    # Ask the user for the next integer and append it to the list
    l.append(int(input()))

# Initialize a variable to store the answer
ans = n - 1

# Initialize a variable to store the previous integer in the list
last = 0

# Iterate through each integer in the list
for i in l:
    # Calculate the absolute difference between the previous integer and the current integer
    # Add 1 to account for the number of steps between the two integers
    ans += abs(last - i) + 1

    # Update the value of the previous integer
    last = i

# Print the value of the answer
print(ans)
