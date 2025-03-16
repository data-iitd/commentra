# Read three integers from input: n (number of elements), a, and b
n, a, b = [int(x) for x in input().split(" ")]

# Read a list of integers from input and store it in lista
lista = [int(x) for x in input().split(" ")]

# Read another list of integers from input and store it in listb
listb = [int(x) for x in input().split(" ")]

# Iterate through the range of n (from 0 to n-1)
for k in range(n):
    # Check if the current index + 1 is present in lista
    if k + 1 in lista:
        # If present, print 1 followed by a space
        print(1, end=" ")
    else:
        # If not present, print 2 followed by a space
        print(2, end=" ")
