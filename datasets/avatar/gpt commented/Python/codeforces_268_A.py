# Read an integer input which represents the number of lists to be processed
n = int(input())

# Initialize an empty list to store the input lists
q = []

# Initialize a counter to keep track of the matching conditions
count = 0

# Loop to read 'n' lines of input and store them in the list 'q'
for i in range(n):
    # Read a line of input, split it into a list of strings, and append it to 'q'
    a = input().split()
    q.append(a)

# Nested loop to compare each list in 'q' with every other list
for j in q:
    for k in q:
        # Skip comparison if both lists are the same
        if k == j:
            continue
        # Check if the first element of list 'j' matches the last element of list 'k'
        elif j[0] == k[len(k) - 1]:
            # Increment the count if the condition is met
            count += 1
        else:
            # Continue to the next iteration if the condition is not met
            continue

# Print the final count of matching conditions
print(count)
