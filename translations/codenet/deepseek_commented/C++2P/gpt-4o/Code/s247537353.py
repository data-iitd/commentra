# Function to check and update the minimum value of a variable
def chmin(a, b):
    if a > b:
        return b
    return a

# Function to check and update the maximum value of a variable
def chmax(a, b):
    if a < b:
        return b
    return a

# Define constants for maximum values
INF = (1 << 30) - 1
INFLL = (1 << 61) - 1
MOD = 1000000007

def main():
    # Fast I/O setup
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Declare variables to store input values
    A = int(data[0])
    B = int(data[1])
    C = int(data[2])
    K = int(data[3])

    # Check if the sum of A and B is greater than or equal to K
    if A + B >= K:
        # Output the minimum of A and K
        print(min(A, K))
    else:
        # Calculate the result by subtracting the excess amount from A
        print(A - (K - (A + B)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
