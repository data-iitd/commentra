import sys

def fun(arr, q, n, m):
    res = 0
    i, j = 0, n
    
    while i <= j:
        md = i + (j - i) // 2
        
        if arr[md] == q:
            return md
        elif arr[md] > q:
            res = md
            j = md - 1
        else:
            i = md + 1
    
    return res

def main():
    # Read the number of elements in the array
    n = int(input().strip())
    
    # Initialize the array to store cumulative sums
    arr = [0] * n
    
    # Read the first element and assign it to the first index of the array
    arr[0] = int(input().strip())
    
    # Populate the array with cumulative sums
    for i in range(1, n):
        # Read the next integer and add it to the previous cumulative sum
        x = int(input().strip())
        arr[i] = x + arr[i - 1]
    
    # Read the number of queries
    m = int(input().strip())
    
    # Initialize the array to store the queries
    q = [0] * m
    
    # Read each query into the array
    for i in range(m):
        q[i] = int(input().strip())
    
    # Process each query and print the result
    for k in range(m):
        print(fun(arr, q[k], n, m) + 1)

if __name__ == "__main__":
    main()
