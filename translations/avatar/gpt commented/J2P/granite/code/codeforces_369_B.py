
import sys

def getPoints(n, k, l, r, sAll, sk):
    # Initialize an array to hold the points for each element
    ans = [l] * n
    
    # Fill the array with the minimum value l
    sAll -= sk + (n - k) * l
    sk -= k * l
    
    # Distribute the remaining points to the last k elements
    while sk > 0:
        idx = n - 1
        while sk > 0 and idx >= n - k:
            ans[idx] += 1 # Increment the points for the selected elements
            sk -= 1 # Decrease the remaining points to distribute
            idx -= 1
    
    # Distribute the remaining total sum to the first n-k elements
    while sAll > 0:
        idx = 0
        while sAll > 0 and idx < n - k:
            ans[idx] += 1 # Increment the points for the non-selected elements
            sAll -= 1 # Decrease the remaining total sum to distribute
            idx += 1
    
    # Return the final points distribution
    return ans

# Read the number of elements (n), number of selected elements (k), 
# lower bound (l), upper bound (r), total sum (sAll), and sum of selected elements (sk)
n, k, l, r, sAll, sk = map(int, sys.stdin.readline().split())

# Call the getPoints method to calculate the points distribution
ans = getPoints(n, k, l, r, sAll, sk)

# Print the resulting points distribution
print(" ".join(map(str, ans)))

