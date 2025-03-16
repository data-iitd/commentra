
def gcd(a, b):
    # Base case: if b is 0, return a as the GCD
    if b == 0:
        return a
    # Recursive case: call gcd with b and the remainder of a divided by b
    return gcd(b, a % b)

def main():
    # Declare variables for the upper limit (k) and loop counters (a, b, c)
    k = 0
    a = 0
    b = 0
    c = 0
    # Initialize the answer variable to accumulate the results
    ans = 0
    
    # Read the upper limit k from user input
    k = int(input())
    
    # Iterate through all combinations of a, b, and c from 1 to k
    for a in range(1, k + 1):
        for b in range(1, k + 1):
            for c in range(1, k + 1):
                # Calculate the GCD of a, b, and c and add it to the answer
                ans += gcd(a, gcd(b, c))
    
    # Print the final accumulated answer
    print(ans)

if __name__ == "__main__":
    main()

