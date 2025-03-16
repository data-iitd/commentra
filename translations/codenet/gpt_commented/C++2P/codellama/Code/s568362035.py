#include <cstdio>

const int MAXN = 1E5 + 10; # Define a constant for the maximum size of arrays

n, m, Q = map(int, input().split()) # Read the number of elements (n), the maximum value (m), and the number of queries (Q)
a = [0] + list(map(int, input().split())) # Array to store the queries
b = [0] * (MAXN) # Array b to store unique values from a
id = [0] * (MAXN) # Array id to map values to their indices
vis = [False] * (MAXN) # Boolean array to track which values have been seen
cnt = [0] * (MAXN) # Array to count occurrences of values

def main():
    # Process the queries to fill array b with unique values from a
    for k in range(1, Q + 1):
        j = Q - k + 1
        if not vis[a[j]]: # If the value has not been seen yet
            b[k] = a[j]
            vis[a[j]] = True

    # Fill the remaining positions in b with the largest unused values up to m
    for j in range(m, 0, -1):
        if not vis[j]: # If the value j has not been seen
            b[j] = j

    # Map each value in b to its index in id
    for i in range(1, m + 1):
        id[b[i]] = i

    flag = True # Initialize a flag to track the validity of the sequence
    cnt[0] = n # Initialize the count of the first value to n

    # Process the queries in reverse order
    for i in range(Q, 0, -1):
        t = id[a[i]] # Get the index of the current query value
        if cnt[t - 1] > 0: # If there are available counts for the previous index
            cnt[t - 1] -= 1 # Decrease the count for the previous index
            cnt[t] += 1 # Increase the count for the current index
            vis[t] = True # Mark the current index as seen
        elif not vis[t]: # If the current index has not been seen
            flag = False # Set the flag to false, indicating an invalid sequence
            break # Exit the loop

    # Find the first index l where count is non-zero
    l = 0
    while cnt[l] == 0:
        l += 1

    # Check if the remaining values in b are in increasing order
    for i in range(l + 1, m):
        flag &= b[i] < b[i + 1] # Update flag based on the order of values in b

    # Output the result based on the flag
    print("Yes" if flag else "No")

if __name__ == "__main__":
    main()

