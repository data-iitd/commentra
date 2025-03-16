
import math

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def main():
    n = int(input())  # Read the number of test cases
    for _ in range(n):
        p, q = map(int, input().split())  # Read the values of p and q for each test case
        l = int(math.sqrt(p**2 + q**2))  # Calculate the length of the hypotenuse
        is_prime_flag = True  # Initialize a flag to check if the number is prime
        for i in range(l):
            for j in range(l):
                x = i**2 + j**2
                if x <= 1 or x >= p**2 + q**2:
                    continue  # Skip if x is out of range
                if (i*p + j*q) % x == 0 and (i*q - j*p) % x == 0:
                    is_prime_flag = False  # Check the conditions
        print("P" if is_prime_flag else "C")  # Print the result

if __name__ == "__main__":
    main()

