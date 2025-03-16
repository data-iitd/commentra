#include <cstdio>

const int MAXN = 1E5 + 10; # Maximum size of the input

n, m, Q = map(int, input().split()) # n: number of elements in the array, m: size of the result array, Q: number of queries
a = [0] + list(map(int, input().split())) # Input array
b = [0] * (MAXN + 1) # Output arrays
id = [0] * (MAXN + 1)
vis = [False] * (MAXN + 1) # Visited flag array
cnt = [0] * (MAXN + 1) # Counter array

# Main function
def main():
    # Read input
    # Read queries
    for i in range(1, Q + 1):
        a[i] = int(input())

    # Initialize variables
    for k in range(0, Q):
        # Find unvisited elements and add them to the output array
        if not vis[a[k + 1]]:
            b[k + 1] = a[k + 1] # Add the element to the output array
            vis[a[k + 1]] = True # Mark it as visited

    # Fill the output array with the remaining unvisited elements
    for j in range(m, 0, -1):
        if not vis[j]:
            b[j] = j # Add the element to the output array

    # Assign indices to the output array elements
    for i in range(1, m + 1):
        id[b[i]] = i # Assign index i to the element b[i]

    # Process queries
    flag = True
    cnt[0] = n # Initialize counter array with the number of elements in the input array
    for i in range(Q, 0, -1):
        t = id[a[i]] # Get the index of the element a[i] in the output array
        if cnt[t - 1] > 0: # If the previous element is still present in the input array
            cnt[t - 1] -= 1 # Decrease its counter
            cnt[t] += 1 # Increase the counter of the current element
            vis[t] = True # Mark it as visited
        else:
            if not vis[t]: # If the current element is not present in the input array
                flag = False # Set the flag to false and break the loop
                break

    # Check the result
    l = 0
    for i in range(0, m):
        if cnt[i] > 0:
            l = i
            break
    for i in range(l + 1, m):
        if cnt[i] > 0:
            flag = False # Check if the output array is sorted in ascending order after the last present element
            break

    # Print the result
    print("Yes" if flag else "No")


