# Read two unsigned integers from standard input
a,b = map(int, input().split())

# Print the binary AND of a and b
print(bin(a&b)[2:])

# Print the binary OR of a and b
print(bin(a|b)[2:])

# Print the binary XOR of a and b
print(bin(a^b)[2:])

