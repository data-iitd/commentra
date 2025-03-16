def search(A, n, key):
    i = 0  # Initialize index to 0
    A.append(key)  # Sentinel value: place the key at the end of the array
    # Loop until the key is found in the array
    while A[i] != key:
        i += 1  # Increment index until the key is found
    # Return true if the key was found before the sentinel, false otherwise
    return i != n

def main():
    n = int(input())  # Read the number of elements in the array
    A = list(map(int, input().split()))  # Read the elements of the array
    q = int(input())  # Read the number of queries
    sum_found = 0  # Initialize sum of found keys

    # Process each query
    for _ in range(q):
        key = int(input())  # Read the key to search for
        # If the key is found in the array, increment the sum
        if search(A, n, key):
            sum_found += 1

    # Output the total count of found keys
    print(sum_found)

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
