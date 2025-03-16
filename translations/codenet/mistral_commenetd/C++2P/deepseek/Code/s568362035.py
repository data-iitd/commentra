MAXN = 100010  # Maximum size of the input

# Initialize variables
n, m, Q = 0, 0, 0  # n: number of elements in the array, m: size of the result array, Q: number of queries
a = [0] * MAXN  # Input array
b = [0] * MAXN  # Output arrays
id = [0] * MAXN  # Index array
vis = [False] * MAXN  # Visited flag array
cnt = [0] * MAXN  # Counter array

# Main function
def main():
    # Read input
    global n, m, Q
    n, m = map(int, input().split())
    Q = int(input())
    for i in range(1, Q + 1):
        a[i] = int(input())  # Read queries

    # Initialize variables
    k = 0
    for j in range(Q, 0, -1):
        # Find unvisited elements and add them to the output array
        if not vis[a[j]]:
            k += 1
            b[k] = a[j]  # Add the element to the output array
            vis[a[j]] = True  # Mark it as visited

    # Fill the output array with the remaining unvisited elements
    for j in range(m, 0, -1):
        if not vis[j]:
            b[m] = j  # Add the element to the output array
            m -= 1

    # Assign indices to the output array elements
    for i in range(1, k + 1):
        id[b[i]] = i  # Assign index i to the element b[i]

    # Process queries
    global flag
    flag = True
    cnt[0] = n  # Initialize counter array with the number of elements in the input array
    for i in range(Q, 0, -1):
        t = id[a[i]]  # Get the index of the element a[i] in the output array
        if cnt[t - 1] > 0:  # If the previous element is still present in the input array
            cnt[t - 1] -= 1  # Decrease its counter
            cnt[t] += 1  # Increase the counter of the current element
            vis[t] = True  # Mark it as visited
        elif not vis[t]:  # If the current element is not present in the input array
            flag = False  # Set the flag to false and break the loop
            break

    # Check the result
    l = 0
    while cnt[l] == 0:
        l += 1  # Find the last element that was present in the input array
    for i in range(l + 1, k):
        if b[i] >= b[i + 1]:  # Check if the output array is sorted in ascending order after the last present element
            flag = False
            break

    # Print the result
    print("Yes" if flag else "No")

# Call the main function
if __name__ == "__main__":
    main()
