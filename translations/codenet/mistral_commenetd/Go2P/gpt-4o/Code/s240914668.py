# Importing required packages
import sys

def main():
    # Initialize input reader
    input = sys.stdin.read
    data = input().split()
    
    # Read number of elements
    n = int(data[0])
    a = list(map(int, data[1:n+1]))

    # Initialize answer variable
    ans = 0

    # Iterate through the array 'a'
    i = 0
    while i < n:
        # Initialize left and right indices
        l, r = i, i + 1

        # Use a while loop to find the next index 'r' such that the difference between 'a[r]' and 'a[l]' is negative
        while r + 1 < n and (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0:
            r += 1

        # Increment the answer variable
        ans += 1

        # Update the index 'i' to 'r' for the next iteration
        i = r

    # Print the answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
