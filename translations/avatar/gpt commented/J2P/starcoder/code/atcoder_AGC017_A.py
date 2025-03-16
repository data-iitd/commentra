import sys

# Method to calculate the binomial coefficient C(n, m)
def C(n, m):
    res = 1 # Initialize result as 1
    # Calculate the numerator part of the binomial coefficient
    for i in range(m - n + 1, m + 1):
        res = res * i # Multiply by i from (m-n+1) to m
    
    # Calculate the denominator part of the binomial coefficient
    for i in range(1, n + 1):
        res = res / i # Divide by i from 1 to n
    
    return res # Return the computed binomial coefficient

if __name__ == "__main__":
    n, p = map(int, sys.stdin.readline().split()) # Read the number of elements and the parity value
    k0 = 0 # Counter for even numbers
    k1 = 0 # Counter for odd numbers
    
    # Count the number of even and odd integers
    for i in range(n):
        x = int(sys.stdin.readline()) # Read the next integer
        if x % 2 == 1:
            k1 += 1 # Increment odd counter
        else:
            k0 += 1 # Increment even counter
    
    ans = 1 # Initialize the answer as 1
    
    # Multiply the answer by 2 raised to the power of the number of even integers
    for i in range(k0):
        ans = ans * 2 # Each even number contributes a factor of 2
    
    # If p is 0, calculate combinations for even selections of odd integers
    if p == 0:
        add = 0 # Initialize the sum for combinations
        # Sum the combinations of choosing even numbers of odd integers
        for i in range(0, k1 + 1, 2):
            add += C(i, k1) # Add C(i, k1) for even i
        
        ans = ans * add # Multiply the answer by the computed combinations
        print(ans) # Output the final answer
    else: # If p is 1, calculate combinations for odd selections of odd integers
        add = 0 # Initialize the sum for combinations
        # Sum the combinations of choosing odd numbers of odd integers
        for i in range(1, k1 + 1, 2):
            add += C(i, k1) # Add C(i, k1) for odd i
        
        ans = ans * add # Multiply the answer by the computed combinations
        print(ans) # Output the final answer

