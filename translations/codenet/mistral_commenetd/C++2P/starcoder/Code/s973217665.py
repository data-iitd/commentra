
# Python 3

# <NAME>
# 2016-02-17
# Prime or Composite

# <BEGIN-OF-CODE>

# Function to check if a number is prime
def isPrime(n):
    if n == 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

# Main function
def main():
    n = int(input()) # Read the number of test cases from standard input
    while n > 0:
        p, q = map(int, input().split()) # Read p and q from standard input
        l = int(sqrt(p*p + q*q)) # Calculate the square root of p^2 + q^2

        isPrime = True # Initialize isPrime to true

        for i in range(l):
            for j in range(l):
                x = i*i + j*j # Calculate x = i^2 + j^2

                if x <= 1:
                    continue # If x is less than or equal to 1, skip to the next iteration
                if x > p*p + q*q:
                    continue # If x is greater than p^2 + q^2, skip to the next iteration

                if ((i*p + j*q) % x == 0 and (i*q - j*p) % x == 0): # Check if p*i + q*j and q*i - p*j are both divisible by x
                    isPrime = False # If so, set isPrime to false
                    break # Exit the inner loop

        print("P" if isPrime else "C") # Print "P" if isPrime is still true, otherwise print "C"

        n -= 1 # Decrement n

# Call main function
main()

# 