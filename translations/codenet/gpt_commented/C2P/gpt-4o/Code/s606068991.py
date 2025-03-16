# Function to print the array elements
def white(n, A):
    # Loop through the array elements except the last one
    for i in range(n - 1):
        print(A[i], end=" ")  # Print each element followed by a space
    print(A[n - 1])  # Print the last element followed by a newline

# Function to perform insertion sort on the array
def insertionsort(n, A):
    # Loop through each element in the array
    for i in range(n):
        # Compare the current element with the previous elements
        for j in range(i):
            # If the current element is smaller, swap it with the previous element
            if A[i] < A[j]:
                A[i], A[j] = A[j], A[i]  # Swap the elements
        # Print the current state of the array after each insertion
        white(n, A)

# Main function
if __name__ == "__main__":
    n = int(input())  # Read the number of elements from user input
    A = list(map(int, input().split()))  # Read the elements of the array from user input
    insertionsort(n, A)  # Call the insertion sort function to sort the array

# <END-OF-CODE>
