import sys

def get_points(n, k, l, r, s_all, s_k):
    ans = [l] * n  # Initializing the scores of all points with the value l

    # Calculating the remaining score after removing the given k points and segments of length l
    s_all -= s_k + (n - k) * l

    # Removing the score of the given k points
    s_k -= k * l

    # Finding the indices of the points to be increased in the first while loop
    idx = n - 1
    while s_k > 0 and idx >= n - k:
        ans[idx] += 1  # Increasing the score of the current point by 1
        idx -= 1
        s_k -= 1  # Decreasing the remaining score by 1

    # Finding the indices of the points to be increased in the second while loop
    while s_all > 0:
        idx = 0
        while s_all > 0 and idx < n - k:
            ans[idx] += 1  # Increasing the score of the current point by 1
            idx += 1
            s_all -= 1  # Decreasing the remaining score by 1

    return ans

# Reading input values from the user
n, k, l, r, s_all, s_k = map(int, sys.stdin.readline().split())

# Calling the get_points() method to get the updated scores of all points
ans = get_points(n, k, l, r, s_all, s_k)

# Printing the updated scores of all points
print(" ".join(map(str, ans)))
