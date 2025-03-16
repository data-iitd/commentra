# Import necessary libraries
import sys

# Define a constant for modulo operations
MOD = 1000000007

def main():
    # Optimize input/output operations
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of elements
    p = list(map(int, data[1:n+1]))  # Read the elements into a list

    ans = 0  # Initialize a counter for the number of valid triplets
    # Loop through the list to check for increasing or decreasing triplets
    for i in range(n - 2):
        # Check if the current triplet is strictly decreasing
        if p[i] > p[i + 1] and p[i + 1] > p[i + 2]:
            ans += 1  # Increment the counter for decreasing triplet

        # Check if the current triplet is strictly increasing
        if p[i] < p[i + 1] and p[i + 1] < p[i + 2]:
            ans += 1  # Increment the counter for increasing triplet

    print(ans)  # Output the total count of valid triplets

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
