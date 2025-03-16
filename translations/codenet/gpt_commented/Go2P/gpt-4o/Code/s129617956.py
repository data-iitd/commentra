import math

def main():
    # Read an integer input from the user
    n = next_int()
    
    # Calculate the integer square root of n
    rt = int(math.sqrt(n))
    
    # Initialize a variable to keep track of the minimum number of digits found
    minf = 100
    
    # Loop through all integers from 1 to the square root of n
    for i in range(1, rt + 1):
        # Check if i is a divisor of n
        if n % i == 0:
            # Calculate the corresponding divisor b
            b = n // i
            
            # Count the number of digits in b
            ndigit = len(str(b))
            
            # Update minf with the minimum number of digits found
            minf = min(minf, ndigit)
    
    # Print the minimum number of digits found among the divisors
    print(minf)

# Function to read an integer from input
def next_int():
    return int(input().strip())

# Function to return the minimum of two integers
def min(i, j):
    return j if i > j else i

if __name__ == "__main__":
    main()

# <END-OF-CODE>
