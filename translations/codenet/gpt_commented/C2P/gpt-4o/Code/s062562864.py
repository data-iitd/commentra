# Declare integer variables to hold input values and results
a, b, c, d = map(int, input().split())

# Calculate the product of the first two integers
i = a * b

# Calculate the product of the last two integers
j = c * d

# Compare the two products and print the larger one
if i > j:
    # If the first product is greater, print it
    print(i)
else:
    # Otherwise, print the second product
    print(j)

# Return 0 to indicate successful completion of the program
# (Note: In Python, we don't need to explicitly return from main)
# <END-OF-CODE>
