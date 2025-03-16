import math

def main():
    n = int(input())  # Read the number of test cases from standard input

    for _ in range(n):  # Process each test case
        p, q = map(int, input().split())  # Read p and q from standard input

        l = int(math.sqrt(p * p + q * q))  # Calculate the square root of p^2 + q^2

        isprime = True  # Initialize isprime to true

        for i in range(l):  # Iterate through all possible integers x from 0 to l^2
            for j in range(l):
                x = i * i + j * j  # Calculate x = i^2 + j^2

                if x <= 1: 
                    continue  # If x is less than or equal to 1, skip to the next iteration
                if x > p * p + q * q: 
                    continue  # If x is greater than p^2 + q^2, skip to the next iteration

                if (i * p + j * q) % x == 0 and (i * q - j * p) % x == 0:  # Check divisibility
                    isprime = False  # If so, set isprime to false
                    break  # Exit the inner loop
            if not isprime:  # If isprime is false, break the outer loop as well
                break

        print("P" if isprime else "C")  # Print "P" if isprime is still true, otherwise print "C"

if __name__ == "__main__":
    main()

# <END-OF-CODE>
