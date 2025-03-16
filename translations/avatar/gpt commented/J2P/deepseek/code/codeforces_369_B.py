import sys

def get_points(n, k, l, r, s_all, s_k):
    # Initialize an array to hold the points for each element
    ans = [l] * n
    
    # Adjust the total sum by subtracting the sum of selected elements and the minimum values
    s_all -= s_k + (n - k) * l
    
    # Adjust the sum of selected elements by subtracting the minimum values
    s_k -= k * l
    
    # Distribute the remaining points to the last k elements
    while s_k > 0:
        idx = n - 1
        while s_k > 0 and idx >= n - k:
            ans[idx] += 1  # Increment the points for the selected elements
            s_k -= 1  # Decrease the remaining points to distribute
            idx -= 1
    
    # Distribute the remaining total sum to the first n-k elements
    while s_all > 0:
        idx = 0
        while s_all > 0 and idx < n - k:
            ans[idx] += 1  # Increment the points for the non-selected elements
            s_all -= 1  # Decrease the remaining total sum to distribute
            idx += 1
    
    # Return the final points distribution
    return ans

# Read the number of elements (n), number of selected elements (k), 
# lower bound (l), upper bound (r), total sum (sAll), and sum of selected elements (sk)
n, k, l, r, s_all, s_k = map(int, sys.stdin.readline().split())

# Call the getPoints method to calculate the points distribution
ans = get_points(n, k, l, r, s_all, s_k)

# Print the resulting points distribution
print(' '.join(map(str, ans)))
