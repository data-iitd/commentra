
# Read the first input value into the variable x
x = int(input())

# Initialize an empty list to store the input values
values = []

# Continue reading input values until a zero is encountered
while x!= 0:
    values.append(x)
    x = int(input())

# Print the case number and the corresponding value from the list
for i, value in enumerate(values):
    print(f"Case {i + 1}: {value}")

