# Function to perform linear search on a list
def linear_search(S, n, key):
    i = 0  # Initialize index for searching
    count = 0  # Initialize count to track if the key is found

    # Loop until the key is found or the end of the list is reached
    while i < n:
        if S[i] == key:
            return count  # Return count (0 if key is found)
        i += 1  # Move to the next index

    count = 1  # Set count to indicate the key was not found
    return count  # Return count

def main():
    n = int(input())  # Read the number of elements in the first list
    S = list(map(int, input().split()))  # Read the elements into the first list S

    q = int(input())  # Read the number of queries
    T = list(map(int, input().split()))  # Read the elements into the second list T (the keys to search for)

    count = 0  # Initialize count for missing keys

    # Loop through each key in T to check if it exists in S
    for key in T:
        # If the key is not found in S, increment the count
        if linear_search(S, n, key) == 0:
            count += 1  # Increment count for each missing key

    # Print the total count of keys that were not found in S
    print(count)

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
