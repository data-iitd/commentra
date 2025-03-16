# Initialize an empty list to store the input values
x = []

# Read the first input value
value = int(input())
x.append(value)

# Continue reading input until a zero is encountered
while value != 0:
    value = int(input())
    x.append(value)

# Print the results
for j in range(len(x) - 1):  # Exclude the last zero
    print(f"Case {j + 1}: {x[j]}")

# End of code
# <END-OF-CODE>
