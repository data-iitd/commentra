import sys

def power(x, n, mod):
    if n == 0:
        return 1
    val = power(x, n // 2, mod)
    val = (val * val) % mod
    if n % 2 == 1:
        val = (val * x) % mod
    return val

def main():
    # Read the first line of input and split it into an array of strings
    sa = sys.stdin.readline().strip().split()
    
    # Parse the first element as an integer 'n'
    n = int(sa[0])
    
    # Read the second line of input and split it into an array of strings
    sa = sys.stdin.readline().strip().split()
    
    # Initialize an integer array 'c' of size 'n'
    c = [int(sa[i]) for i in range(n)]
    
    # Define a modulus value for calculations
    mod = 1000000007
    
    # If there is only one element, calculate and print the result directly
    if n == 1:
        print(c[0] * 2 % mod)
        return
    
    # Sort the array 'c'
    c.sort()
    
    # Calculate powers of 2 for later use
    b = power(2, n, mod)
    a = power(2, n - 2, mod)
    
    # Initialize the answer variable
    ans = 0
    
    # Calculate the final answer using a loop
    for i in range(2, n + 2):
        # Calculate the value for the current iteration
        val = a * i % mod
        val = val * c[n + 1 - i] % mod
        
        # Accumulate the result
        ans = (ans + val) % mod
    
    # Multiply the accumulated answer by 'b' and take modulus
    ans = (ans * b) % mod
    
    # Print the final result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
