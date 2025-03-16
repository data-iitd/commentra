import sys

# Function to calculate x^n % mod
def power(x, n):
    if n == 0:
        return 1 # Base case: x^0 is 1
    val = power(x, n/2) # Recursive call to calculate x^(n/2)
    val = val * val % mod # Squaring the result
    if n % 2 == 1:
        val = val * x % mod # Multiplying by x if n is odd
    return val # Returning the result

# Main function
if __name__ == "__main__":
    mod = 1000000007 # Defining the modulo value
    n = int(sys.stdin.readline().strip()) # Reading the first line and stripping the newline character
    c = [int(x) for x in sys.stdin.readline().strip().split(" ")] # Reading the second line and splitting by spaces and stripping the newline character
    if n == 1:
        print(c[0] * 2 % mod) # If n is 1, print the result directly
        exit() # Exit the program as no further computation is needed
    c.sort() # Sorting the array c in ascending order
    b = power(2, n) # Calculating 2^n
    a = power(2, n - 2) # Calculating 2^(n-2)
    ans = 0 # Initializing the answer variable
    for i in range(2, n + 1):
        val = a * i % mod # Intermediate calculation
        val = val * c[n + 1 - i] % mod # Intermediate calculation
        ans += val # Adding to the answer
    ans = ans * b % mod # Multiplying the answer by b
    print(ans) # Printing the final result

