# Function to search for a key in an array
def search(A, n, key):
    # Add the key to the end of the array
    A.append(key)
    # Search for the key in the array using a while loop
    i = 0
    while A[i] != key:
        i += 1
    # Return True if the key was found before the end of the array, otherwise return False
    return i != n

def main():
    # Read the number of elements in the array from the user
    n = int(input())
    # Read the elements of the array from the user
    A = list(map(int, input().split()))
    # Read the number of queries from the user
    q = int(input())
    sum_found = 0  # Variable to store the number of keys found

    # For each query, search for the key in the array and if it is found, increment the sum
    for _ in range(q):
        key = int(input())  # Read the key to be searched for
        # Call the search function to find the key in the array
        if search(A, n, key):  # If the key is found, increment the sum
            sum_found += 1

    # Print the number of keys found
    print(sum_found)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
