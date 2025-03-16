

# Python code to search for a key in an array

# Function to search for a key in an array
def search(A, n, key):
    i = 0
    # Add the key to the end of the array
    A[n] = key
    # Search for the key in the array using a while loop
    while A[i]!= key:
        i += 1
    # Return 1 if the key was found before the end of the array, otherwise return 0
    return i!= n

# Main function
def main():
    n = int(input("Enter the number of elements in the array: ")) # Number of elements in the array
    A = [0] * (n + 1) # Array to store the elements
    q = int(input("Enter the number of queries: ")) # Number of queries
    sum = 0 # Variable to store the number of keys found
    i = 0 # Loop counter

    # Read the elements of the array from the user
    for i in range(n):
        A[i] = int(input("Enter element " + str(i) + ": "))

    # For each query, search for the key in the array and if it is found, increment the sum
    for i in range(q):
        key = int(input("Enter the key to be searched for: ")) # Read the key to be searched for
        # Call the search function to find the key in the array
        if search(A, n, key):
            sum += 1 # If the key is found, increment the sum

    # Print the number of keys found
    print("Number of keys found:", sum)

# Call the main function
if __name__ == "__main__":
    main()

