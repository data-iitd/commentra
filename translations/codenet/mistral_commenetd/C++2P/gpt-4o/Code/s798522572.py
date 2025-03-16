# Main function starts here
def main():
    # Initialize variables
    N, T = map(int, input().split())  # N is the number of elements in the array A, T is an input value

    # Allocate memory for an integer array A of size N
    A = list(map(int, input().split()))

    # Allocate memory for a list B of size N
    B = [0] * N

    # Initialize variable m with the minimum value among the first two elements of array A
    m = A[0]
    if A[1] < m:
        m = A[1]

    # Set the first element of list B with the difference between the second element of array A and the initialized value of m
    B[1] = A[1] - m

    # Iterate through the remaining elements of array A starting from the third one
    for i in range(2, N):
        # Update the value of m with the minimum value between it and the current element of array A
        m = min(m, A[i])

        # Set the current element of list B with the difference between the current element of array A and the updated value of m
        B[i] = A[i] - m

    # Print the output value to the standard output
    print(B.count(max(B)))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
