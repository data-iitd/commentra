

# Function to find the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    # Base case: if b is 0, return a as the GCD
    if b==0:
        return a
    # Recursive case: call gcd function with b and the remainder of a divided by b
    return gcd(b, a%b)

# Main function
if __name__ == "__main__":
    # Initialize variables
    k = int(input("Enter a positive integer k: "))
    ans = 0
    # Loop through all possible combinations of a, b and c from 1 to k
    for a in range(1, k+1):
        # Inner loop to find the GCD of b and c
        for b in range(1, k+1):
            # Inner most loop to find the GCD of a, b and c
            for c in range(1, k+1):
                # Add the result of GCD(a, GCD(b, c)) to the answer
                ans += gcd(a, gcd(b, c))
    # Print the final answer
    print("The sum of GCD of all combinations of three numbers from 1 to k is: ", ans)
    # End of code