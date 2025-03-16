# Declare variables a, b, c, d, and e
a, b, c, d, e = map(int, input().split())

# Create a list named al with the values of variables a, b, c, d, and e
al = [a, b, c, d, e]

# Iterate through each element i in the list al starting from the index 0
for n, i in enumerate(al):
    # Check if the current element i is equal to 0
    if i == 0:
        # Print the index number n+1 as output
        print(n + 1)
        # Break the loop as soon as the first zero element is found
        break

# <END-OF-CODE>
