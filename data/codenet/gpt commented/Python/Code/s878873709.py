import sys

# Set up input reading and constants
readline = sys.stdin.readline
MOD = 10 ** 9 + 7  # A large prime number for modulo operations
INF = float('INF')  # Represents infinity
sys.setrecursionlimit(10 ** 5)  # Increase recursion limit for deep recursions if needed

def main():
    # Read the integer N from input
    N = int(readline())
    
    # Define a set of powers of 2
    s = {1, 2, 4, 8, 16, 32, 64}
    
    # Initialize the answer variable
    ans = 0

    # Iterate through numbers from 1 to N
    for i in range(1, N + 1):
        # Check if the current number is in the set of powers of 2
        if i in s:
            ans = i  # Update the answer to the current power of 2

    # Print the largest power of 2 found in the range
    print(ans)

# Entry point of the program
if __name__ == '__main__':
    main()
