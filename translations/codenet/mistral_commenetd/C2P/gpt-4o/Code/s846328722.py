# Function definition for linear search
def linear_search(arr, n, key):
    i = 0  # Initializing index i to zero

    # Adding the key to the end of the array for the case when the key is already present at the beginning
    arr.append(key)

    # Linear search algorithm to find the index of the key in the array
    while arr[i] != key:
        i += 1  # Incrementing index i until the key is found

    # Returning True if the key is found, and False otherwise
    return i != n

def main():
    n = int(input())  # Reading the size of the array from user input
    s = list(map(int, input().split()))  # Reading array elements into the list s

    q = int(input())  # Reading the number of queries from user input
    count = 0  # Initializing count to zero

    # Looping through each query
    for _ in range(q):
        t = int(input())  # Reading a query element from user input

        # Calling the linear search function to check if the query element is present in the array
        if linear_search(s, n, t):  # If the query element is present, increment the count
            count += 1

    # Printing the final count of query elements present in the array
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
