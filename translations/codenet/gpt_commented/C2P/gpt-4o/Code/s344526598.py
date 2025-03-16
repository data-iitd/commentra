# Declare an empty list to store the input values
x = []

# Read the first input value
value = int(input())
x.append(value)

# Continue reading input values until a zero is encountered
while value != 0:
    value = int(input())
    x.append(value)

# Print the case number and the corresponding value from the list
for j in range(len(x) - 1):  # Exclude the last zero
    print(f"Case {j + 1}: {x[j]}")

# Indicate that the program ended successfully
# <END-OF-CODE>
