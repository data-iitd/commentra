# <START-OF-CODE>
# Read two integers from standard input
a = int(input())
b = int(input())

# Determine the value of'result' based on the values of 'a' and 'b'
if a > b:
    result = 2 * a - 1
elif a == b:
    result = 2 * a
else:
    result = 2 * b - 1

# Output the value of'result' to standard output
print(result)
# 