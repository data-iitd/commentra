import math

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def main():
    n = int(input())  # Read the number of test cases
    while n > 0:
        p, q = map(int, input().split())  # Read the values of p and q for each test case
        l = int(math.sqrt(p*p + q*q))  # Calculate the length of the hypotenuse
        isprime = True  # Initialize a flag to check if the number is prime
        for i in range(l):
            for j in range(l):
                x = i*i + j*j  # Calculate the sum of squares
                if x <= 1 or x >= p*p + q*q:
                    continue  # Skip if x is out of range
                if (i*p + j*q) % x == 0 and (i*q - j*p) % x == 0:
                    isprime = False  # Check the conditions
                    break  # Break out of the loop if not prime
            if not isprime:
                break
        print("P" if isprime else "C")  # Print the result
        n -= 1

main()
