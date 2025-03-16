def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the number of elements in the array
    n = int(data[0])
    
    # Initialize the array to store cumulative sums
    arr = [0] * n
    
    # Read the first element and assign it to the first index of the array
    arr[0] = int(data[1])
    
    # Populate the array with cumulative sums
    for i in range(1, n):
        x = int(data[i + 1])
        arr[i] = x + arr[i - 1]
    
    # Read the number of queries
    m = int(data[n + 1])
    
    # Initialize the array to store the queries
    q = [0] * m
    
    # Read each query into the array
    for i in range(m):
        q[i] = int(data[n + 2 + i])
    
    # Process each query and print the result
    for k in range(m):
        print(fun(arr, q[k], n) + 1)

# Function to perform binary search on the cumulative sum array
def fun(arr, q, n):
    res = 0  # Variable to store the result index
    i, j = 0, n - 1  # Initialize pointers for binary search
    
    # Perform binary search to find the appropriate index
    while i <= j:
        md = i + (j - i) // 2  # Calculate the mid index
        
        # If the middle element is equal to the query, return the index
        if arr[md] == q:
            return md
        # If the middle element is greater than the query, adjust the search range
        elif arr[md] > q:
            res = md  # Update result to the current mid index
            j = md - 1  # Move the end pointer left
        else:
            i = md + 1  # Move the start pointer right
    
    # Return the last found index where the cumulative sum is less than the query
    return res

if __name__ == "__main__":
    main()

# <END-OF-CODE>
