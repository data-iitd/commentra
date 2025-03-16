def linear_search(arr, n, key):
    # Modify the array to facilitate the search
    arr.append(key)
    
    # Perform the linear search
    i = 0
    while arr[i] != key:
        i += 1
    
    # Return true if the key is found, false otherwise
    return i != n

def main():
    # Read the number of elements
    n = int(input())
    
    # Read the elements into the array s
    s = list(map(int, input().split()))
    
    # Read the number of queries
    q = int(input())
    
    count = 0
    
    # Perform a linear search for each query
    for _ in range(q):
        t = int(input())
        if linear_search(s, n, t):
            count += 1
    
    # Print the total count of successful searches
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
