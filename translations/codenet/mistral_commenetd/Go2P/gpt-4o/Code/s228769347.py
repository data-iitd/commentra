# Importing required modules
import sys
import bisect

def main():
    # Read the number of elements in the array
    n = int(sys.stdin.readline().strip())
    
    # Read the elements of the array
    ll = list(map(int, sys.stdin.readline().strip().split()))
    
    # Sort the list in ascending order
    ll.sort()
    
    # Initialize the answer variable to 0
    ans = 0
    
    # Iterate through all possible pairs of elements
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            # Calculate the sum of the current pair
            current_sum = ll[i] + ll[j]
            # Use binary search to find the index of the first element greater than the current sum
            l = bisect.bisect_right(ll, current_sum)
            # Update the answer variable
            ans += l - (j + 1)
    
    # Print the answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
