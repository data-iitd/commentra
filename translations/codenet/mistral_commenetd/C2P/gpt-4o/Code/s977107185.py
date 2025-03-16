# Main function starts here
def main():
    # Declare variables
    N = int(input())  # Read the number of elements in the array from user input
    A = []  # Initialize an empty list A
    count = 0  # Initialize counter variable count to 0

    # Read elements of the array A from user input
    for i in range(N):
        A.append(int(input()))  # Read an element of the array A

    # Perform bubble sort on the array A
    for i in range(N - 1):
        for j in range(N - 1, i, -1):  # Iterate through the array from last to first
            if A[j] < A[j - 1]:  # Check if the current element is smaller than the previous one
                # Swap the elements if they are in wrong order
                A[j], A[j - 1] = A[j - 1], A[j]
                count += 1  # Increment the counter for each swap

    # Print the sorted array A
    print(" ".join(map(str, A)))  # Print elements of the array A with spaces in between

    # Print the number of swaps (count) made during sorting
    print(count)

# Call the main function
if __name__ == "__main__":
    main()

# Main function ends here with a return value of 0
# <END-OF-CODE>
