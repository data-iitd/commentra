import sys

def main():
    # Read the number of pairs (n) and the minimum score (s)
    n, s = map(int, sys.stdin.readline().split())
    
    # Initialize a variable to keep track of the maximum sum of pairs
    max_sum = 0
    
    # Loop through each pair of integers
    for _ in range(n):
        f, t = map(int, sys.stdin.readline().split())
        # Update max_sum if the sum of f and t is greater than the current max_sum
        if max_sum < f + t:
            max_sum = f + t
    
    # Print the maximum value between max_sum and s
    print(max(max_sum, s))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
