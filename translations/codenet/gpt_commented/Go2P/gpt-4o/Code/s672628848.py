# Declare five integer variables to hold input values
a, b, c, d, e = map(int, input().split())

# Create a list containing the input integers
al = [a, b, c, d, e]

# Iterate over the list to find the first occurrence of zero
for n, i in enumerate(al):
    # Check if the current element is zero
    if i == 0:
        # Print the index (1-based) of the first zero found and exit the loop
        print(n + 1)
        break

# <END-OF-CODE>
