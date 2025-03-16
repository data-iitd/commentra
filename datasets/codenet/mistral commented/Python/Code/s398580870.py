
n, k = map(int, input().split())
# Take the integer values of n and k from the user's input

if k % 2 == 1:
# Check if k is odd
    print((n // k) ** 3)
# If k is odd, calculate the cube of the quotient of n by k and print the result
else:
# If k is even, we need to calculate the cube of two different quotients
    print((n // k) ** 3 + ((n + k // 2) // k) ** 3)
# Print the sum of the cubes of the two quotients

# The first quotient is n divided by k
# The second quotient is n plus half of k divided by k