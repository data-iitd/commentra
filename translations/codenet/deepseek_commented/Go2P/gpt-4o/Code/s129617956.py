import math
import sys

def next_int():
    return int(sys.stdin.readline().strip())

def min_value(i, j):
    return j if i > j else i

def main():
    # Read an integer n from the standard input
    n = next_int()
    
    # Calculate the square root of n and store it in rt
    rt = int(math.sqrt(n))
    
    # Initialize minf to 100, which will hold the minimum number of digits
    minf = 100
    
    # Iterate from 1 to rt + 1 to find divisors of n
    for i in range(1, rt + 1):
        if n % i == 0:
            # If i is a divisor of n, calculate the quotient b
            b = n // i
            
            # Count the number of digits in b
            ndigit = len(str(b))
            
            # Update minf with the minimum number of digits found
            minf = min_value(minf, ndigit)
    
    # Print the minimum number of digits
    print(minf)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
