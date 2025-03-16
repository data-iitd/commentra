import sys

def read_int():
    return int(sys.stdin.readline().strip())

def solve():
    K = read_int()
    
    # Check if K is even or divisible by 5, return -1 if true
    if K % 2 == 0 or K % 5 == 0:
        return -1
    
    # If K is divisible by 7, divide it by 7
    if K % 7 == 0:
        K //= 7
    
    # Multiply K by 9 as part of the calculation
    K *= 9
    
    # Initialize the answer counter
    ans = 1
    
    # Calculate the remainder of 10 divided by K
    remainder = 10 % K
    
    # Loop until the remainder is 1
    while remainder != 1:
        # Increment the answer counter
        ans += 1
        # Update the remainder for the next iteration
        remainder = remainder * 10 % K
    
    # Return the final answer
    return ans

if __name__ == "__main__":
    print(solve())

# <END-OF-CODE>
