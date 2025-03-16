# Define a function to read input and process the graph
def main():
    # Read the number of vertices (or nodes)
    n = int(input())

    # Initialize a list to store the count of edges for each vertex
    ans = [0] * n

    # Read n-1 edges and count the occurrences for each vertex
    for _ in range(n - 1):
        a = int(input())  # Read the vertex index
        a -= 1  # Convert to 0-based index
        ans[a] += 1  # Increment the count for the corresponding vertex

    # Output the count of edges for each vertex
    for count in ans:
        print(count)  # Print the count for each vertex

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
