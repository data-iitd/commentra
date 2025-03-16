def linear_search(arr, n, key):
    # Sentinel value: place the key at the end of the array
    arr.append(key)
    
    i = 0
    # Search for the key in the array
    while arr[i] != key:
        i += 1
    
    # Return true if the key was found within the original array bounds
    return i != n

def main():
    n = int(input())  # Read the number of elements in the array
    s = list(map(int, input().split()))  # Read n elements into the array s

    q = int(input())  # Read the number of queries
    count = 0

    # Process each query to check if the element exists in the array
    for _ in range(q):
        t = int(input())  # Read the query element
        # Use linear search to check if the element t is in the array s
        if linear_search(s, n, t):
            count += 1  # Increment count if found

    # Output the total count of found elements
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
