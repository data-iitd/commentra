
# Python code to perform linear search

# Function to perform linear search
def linersearch(a, n, key):
    i = 0
    # Search for the key in the array
    while a[i]!= key:
        i += 1
    # Return true if the key was found within the original array bounds
    return i!= n

# Main function
def main():
    n = int(input("Enter the number of elements in the array: "))
    # Read n elements into the array s
    s = [int(input("Enter element %d: " % (i+1))) for i in range(n)]
    q = int(input("Enter the number of queries: "))
    count = 0
    # Process each query to check if the element exists in the array
    for i in range(q):
        t = int(input("Enter query element %d: " % (i+1)))
        # Use linear search to check if the element t is in the array s
        if linersearch(s, n, t):
            count += 1
    # Output the total count of found elements
    print("Total count of found elements:", count)

# Call the main function
if __name__ == "__main__":
    main()

