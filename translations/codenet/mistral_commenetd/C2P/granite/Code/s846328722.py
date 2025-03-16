
# Python code to implement linear search

# Function definition for linear search
def linersearch(a, n, key):
    i = 0 # Initializing index i to zero

    # Adding the key to the end of the array for the case when the key is already present at the beginning
    a.append(key)

    # Linear search algorithm to find the index of the key in the array
    while a[i]!= key:
        i += 1 # Incrementing index i until the key is found

    # Returning 1 if the key is found, and 0 otherwise
    return i!= n

# Main function to read input and call the linear search function
def main():
    n = int(input("Enter the size of the array: ")) # Reading the size of the array from user input
    s = list(map(int, input("Enter the elements of the array separated by spaces: ").split())) # Reading array elements into the array s
    q = int(input("Enter the number of queries: ")) # Reading the number of queries from user input
    count = 0 # Initializing count to zero

    # Looping through each query
    for i in range(q):
        t = int(input("Enter the query element: ")) # Reading a query element from user input

        # Calling the linear search function to check if the query element is present in the array
        if linersearch(s, n, t):
            count += 1 # If the query element is present, increment the count

    # Printing the final count of query elements present in the array
    print(count)

# Calling the main function
if __name__ == "__main__":
    main()

