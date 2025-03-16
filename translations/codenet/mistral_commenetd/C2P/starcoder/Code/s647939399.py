
# Declare variables
m = ''
a = 0
b = 0
c = [0]*256

# Initialize array c with zeros
for i in range(256):
    c[i] = 0

# Read input values of a, m, and b from the user
while True:
    a, m, b = map(int, input().split())
    if m == '?':
        break
    if m == '+':
        c[i] = a + b
    if m == '-':
        c[i] = a - b
    if m == '*':
        c[i] = a * b
    if m == '/':
        c[i] = a / b

# Print the results of the arithmetic operations
for j in range(i):
    print(c[j])

