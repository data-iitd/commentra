# Function to perform linear search on a list
def linear_search(S, n, key):
    i = 0  # Initialize index variable i to 0

    # Search for the key in the list S until it is found or the end of the list is reached
    while i < n:
        if S[i] == key:
            return 0  # If key is found, return 0 to indicate that it was found
        i += 1  # Increment i by 1 for each iteration

    return 1  # Return 1 if key is not found in the list

# Main function to read input and call linear_search function
def main():
    n = int(input("Enter the size of the array S: "))  # Read the size of the list S from the user
    S = []  # Initialize list S

    # Read the elements of list S from the user
    print(f"Enter {n} integers for array S:")
    for i in range(n):
        S.append(int(input(f"Enter integer S[{i}]: ")))

    q = int(input("Enter the number of queries: "))  # Read the number of queries from the user
    T = []  # Initialize list T

    # Read the elements of list T from the user
    print(f"Enter {q} integers for array T:")
    for j in range(q):
        T.append(int(input(f"Enter integer T[{j}]: ")))

    count = 0  # Initialize count variable to 0

    # Call linear_search function for each element of list T and increment count if key is not found
    for j in range(q):
        key = T[j]  # Assign the current element of list T to key variable
        if linear_search(S, n, key) == 1:  # Call linear_search function and check if count is 1 (key not found)
            count += 1  # Increment count if key is not found

    # Print the final count to the user
    print(f"Number of integers in array S that are not present in array T: {count}")

# Execute the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
