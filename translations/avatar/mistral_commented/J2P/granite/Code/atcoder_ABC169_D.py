
import math

# Function to calculate the number of prime factors in a given number
def prime_factors(n):
    count = 0
    while n % 2 == 0:
        count += 1
        n = n / 2
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            count += 1
            n = n / i
    if n > 2:
        count += 1
    return count

# Taking input from the user
n = int(input("Enter a number: "))

# Calculating the number of prime factors in the given number
answer = prime_factors(n)

# Printing the result
print("The number of prime factors in", n, "is", answer)

