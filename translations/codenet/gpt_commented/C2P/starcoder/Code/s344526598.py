# <START-OF-CODE>

# Declare variables
x = [0] * 10000

# Initialize the array x with zeros
for i in range(10000):
    x[i] = 0

# Read the first input value into the array
i = 0
x[i] = int(input())

# Continue reading input values until a zero is encountered
while x[i]!= 0:
    i += 1
    x[i] = int(input())

# Print the case number and the corresponding value from the array
for j in range(i):
    print("Case %d: %d" % (j + 1, x[j]))

# 