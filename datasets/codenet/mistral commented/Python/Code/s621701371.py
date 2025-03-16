# Take the initial string as input
s = input()

# Take the number of operations as input
q = int(input())

# Initialize a list to store the operations
qs = [input().split() for i in range(q)]

# Initialize a flag variable to keep track of the current state
n = False

# Initialize empty strings to store the left and right parts of the final string
left = ""
right = ""

# Iterate through each operation in the list
for operation in qs:
    # Check if the current operation is of type 1
    if operation[0] == '1':
        # Toggle the flag variable
        n = not n

    # Check if the current operation is of type 2
    elif operation[0] == '2':
        # Extract the parameters from the operation
        t, f, c = operation

        # Convert the flag value to an integer
        f = int(f)

        # If the flag is True, flip it
        if n:
            f = 1 if f != 1 else 2

        # Based on the value of the flag and the operation type, update the left or right string accordingly
        if f == 1:
            left = c + left
        elif f == 2:
            right += c

# Construct the final string by concatenating the left, input string, and right parts
s = left + s + right

# Print the final string with the reverse order if the flag is True
print(s[::-1] if n else s)
