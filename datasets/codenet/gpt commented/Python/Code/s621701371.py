# Read the initial string input from the user
s = input()

# Read the number of operations to be performed
q = int(input())

# Read each operation and store them in a list
qs = [input().split() for i in range(q)]

# Initialize a flag to determine if the string should be reversed
n = False

# Initialize variables to hold characters to be added to the left and right of the string
left = right = ""

# Process each operation in the list of operations
for operation in qs:
    # Check if the operation is to toggle the reverse flag
    if operation[0] == '1':
        n = not n  # Toggle the value of n (True to False or False to True)
    
    # Check if the operation is to add a character to either the left or right
    if operation[0] == '2':
        t, f, c = operation  # Unpack the operation details
        f = int(f)  # Convert the position indicator to an integer
        
        # If the reverse flag is set, switch the position indicator
        if n:
            f = 1 if f != 1 else 2  # If f is 1, change it to 2 and vice versa
        
        # Add the character to the left or right based on the position indicator
        if f == 1:
            left = c + left  # Add character to the left side
        elif f == 2:
            right += c  # Add character to the right side

# Construct the final string by combining left, original string, and right
s = left + s + right

# Print the final string, reversing it if the reverse flag is set
print(s[::-1] if n else s)
