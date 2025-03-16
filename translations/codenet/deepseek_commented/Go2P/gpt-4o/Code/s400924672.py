r, D, x = map(int, input().split())  # Read three integers from standard input

for i in range(1, 11):  # Loop 10 times
    print(r * x - D)  # Print the result of the calculation
    x = r * x - D  # Update x for the next iteration

# <END-OF-CODE>
