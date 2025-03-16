# Import the necessary module
import sys

def main():
    # Read the number of elements
    n = int(sys.stdin.readline().strip())
    
    # Initialize lists to store the elements
    h = [0] * n
    g = [0] * n
    
    # Read n pairs of integers from the standard input
    for i in range(n):
        h[i], g[i] = map(int, sys.stdin.readline().strip().split())
    
    # Initialize the result variable to 0
    result = 0
    
    # Iterate through each element in list h
    for i in range(n):
        # Compare each element in list h with each element in list g
        for j in range(n):
            if h[i] == g[j]:
                # If a match is found, increment the result
                result += 1
    
    # Print the value of result
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
