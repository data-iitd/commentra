def search(A, n, key):
    # Add the key to the end of the array to handle the case where the key is not found
    A.append(key)
    # Loop until the key is found in the array
    i = 0
    while A[i] != key:
        i += 1
    # Return True if the key is found, otherwise return False
    return i != n

def main():
    # Read the size of the array
    n = int(input())
    # Read the array elements
    A = list(map(int, input().split()))
    # Read the number of queries
    q = int(input())
    sum_count = 0
    
    # Process each query
    for _ in range(q):
        key = int(input())
        # Perform the search operation for the current query element
        if search(A, n, key):
            sum_count += 1
            
    # Print the count of successful searches
    print(sum_count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
