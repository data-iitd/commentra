
X = int(input())  # Take an integer input from the user and store it in X
prime = [True] * (100010)  # Initialize a list 'prime' with 100010 elements, all set to True
prime[0] = False  # 0 is not a prime number
prime[1] = False  # 1 is not a prime number

# Mark all even numbers (except 2) as not prime
for i in range(4, 100010, 2):
    prime[i] = False

# Use a while loop to mark non-prime numbers using the Sieve of Eratosthenes algorithm
i = 3
while (i * i <= 100008):
    if prime[i]:
        for j in range(i + i, 100008, i):
            prime[j] = False
    i += 2

# Iterate through the range from X to 100008 and print the first prime number found
for i in range(X, 100008):
    if prime[i]:
        print(i)
        break

