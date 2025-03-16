# Ask user for the number of arrays (n) they want to input
n = int(input())

# Create an empty list called 'q' to store these arrays
q = []

# Use a for loop to iterate through the range of 'n' and for each iteration,
# ask the user for an array (a) and append it to our list 'q'
for i in range(n):
    # Ask user for an array (a)
    a = input().split()
    # Append array 'a' to our list 'q'
    q.append(a)

# Use another for loop to iterate through each array in our list 'q'
for j in q:
    # For each array 'j', use another for loop to iterate through every other array in our list 'q'
    for k in q:
        # Exclude the current array 'j' from comparison using 'continue' statement if they are the same
        if k == j:
            continue
        # Check if the last element of the second array 'k' matches the first element of the first array 'j'
        elif j[0] == k[-1]:
            # If it does, increment our 'count' variable
            count += 1

# Finally, print out the value of our 'count' variable
print(count)
