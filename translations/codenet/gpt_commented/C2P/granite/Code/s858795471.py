
# Python code to search for a key in an array

# Function to search for a key in the array A of size n
def search(A, n, key):
    i = 0 # Initialize index to 0
    A[n] = key # Sentinel value: place the key at the end of the array
    # Loop until the key is found in the array
    while A[i]!= key: i += 1 # Increment index until the key is found
    # Return true if the key was found before the sentinel, false otherwise
    return i!= n

# Main function
def main():
    n = int(input("Enter the number of elements in the array: ")) # Read the number of elements in the array
    A = [int(input("Enter element " + str(i) + ": ")) for i in range(n)] # Read the elements of the array
    q = int(input("Enter the number of queries: ")) # Read the number of queries
    sum = 0 # Initialize sum to 0
    # Process each query
    for i in range(q):
        key = int(input("Enter the key to search for: ")) # Read the key to search for
        # If the key is found in the array, increment the sum
        if search(A, n, key): sum += 1
    # Output the total count of found keys
    print("Total count of found keys:", sum)

# Call the main function
if __name__ == "__main__":
    main()

