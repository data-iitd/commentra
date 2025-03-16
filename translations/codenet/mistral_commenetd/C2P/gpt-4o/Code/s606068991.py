# Function to print the first n-1 elements of a list
def white(n, A):
    # Loop to print the first n-1 elements of the list
    for i in range(n - 1):
        print(A[i], end=" ")
    # Print the last element of the list
    print(A[n - 1])

# Function to implement insertion sort algorithm
def insertionsort(n, A):
    # Loop to sort the list using insertion sort algorithm
    for i in range(n):
        # Inner loop to find the position of the current element in sorted list
        for j in range(i):
            # Swap if current element is smaller than the previous one
            if A[i] < A[j]:
                # Swap the elements
                A[i], A[j] = A[j], A[i]
        # Call the white function to print the sorted list after each iteration
        white(n, A)

# Main function to take input and call the insertion sort function
if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))
    A = list(map(int, input("Enter the elements of the array: ").split()))
    # Call the insertion sort function to sort the list
    insertionsort(n, A)

# <END-OF-CODE>
