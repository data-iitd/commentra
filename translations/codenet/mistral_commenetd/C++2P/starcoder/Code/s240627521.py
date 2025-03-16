
# Declare a function called "main"
def main():
    # Read the number of elements from the standard input
    N = int(input())
    # Declare and initialize a list A of size N with default-constructed elements
    A = [0]*N
    # Iterate through the range [0, N) and read each element into the list
    for i in range(N):
        A[i] = int(input())
    # Sort the list A in descending order
    A.sort(reverse=True)
    # Initialize the maximum difference to an infinite value
    max = float("inf")
    # Initialize the index of the second smallest element to 0
    index = 0
    # Iterate through the range [1, N)
    for i in range(1, N):
        # Check if the current difference is greater than the maximum difference
        if max > abs(A[0] - 2*A[i]):
            # Update the maximum difference if it is
            max = abs(A[0] - 2*A[i])
            # Update the index of the second smallest element
            index = i
    # Output the smallest and second smallest elements
    print(A[0], A[index])

# Call the "main" function
main()

