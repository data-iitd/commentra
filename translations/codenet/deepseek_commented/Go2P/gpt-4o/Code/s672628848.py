# Declare five integer variables to hold input values
a, b, c, d, e = map(int, input().split())

# Create a list containing the five integers
al = [a, b, c, d, e]

# Iterate over the list using a for loop with enumerate
for n, i in enumerate(al):
    # Check if the current element is equal to 0
    if i == 0:
        # Print the position of the element (1-based index) and break out of the loop
        print(n + 1)
        break

# <END-OF-CODE>
