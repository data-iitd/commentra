import math

def main():
    n = int(input())  # Read the number of test cases
    for _ in range(n):
        p, q = map(int, input().split())  # Read the values of p and q for each test case
        l = int(math.sqrt(p * p + q * q))  # Calculate the length of the hypotenuse
        isprime = True  # Initialize a flag to check if the number is prime
        
        for i in range(l):
            for j in range(l):  # Loop through all pairs (i, j) within the range of l
                x = i * i + j * j  # Calculate the sum of squares
                if x <= 1 or x >= p * p + q * q:
                    continue  # Skip if x is out of range
                if (i * p + j * q) % x == 0 and (i * q - j * p) % x == 0:
                    isprime = False  # Check the conditions
        
        print("P" if isprime else "C")  # Print the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
