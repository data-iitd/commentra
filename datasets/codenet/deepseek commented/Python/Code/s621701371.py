s = input()  # Read the initial string `s` from input
q = int(input())  # Read the number of operations `q` from input
qs = [input().split() for i in range(q)]  # Read each operation and store in a list `qs`

# Initialize a boolean `n` to False
n = False
# Initialize two empty strings `left` and `right` to store parts of the string
left = right = ""

# Iterate over each operation in `qs`
for operation in qs:
    if operation[0] == '1':  # Check if the operation is of type '1'
        # Toggle the boolean `n`
        n = not n
    if operation[0] == '2':  # Check if the operation is of type '2'
        # Unpack the operation components: type, position, and string to append
        t, f, c = operation
        f = int(f)  # Convert the position to an integer
        if n:
            f = 1 if f != 1 else 2  # Adjust the position based on the value of `n`
        if f == 1:
            # Append the string `c` to the left of `left`
            left = c + left
        elif f == 2:
            # Append the string `c` to the right of `right`
            right += c

# Concatenate `left`, `s`, and `right` to form the final string
s = left + s + right

# Print the string `s` in reverse if `n` is `True`, otherwise print `s` as is
print(s[::-1] if n else s)
