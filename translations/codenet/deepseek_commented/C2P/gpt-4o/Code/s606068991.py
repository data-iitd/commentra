# Function to print the array elements
def white(n, A):
    for i in range(n - 1):
        print(A[i], end=' ')
    print(A[n - 1])

# Function to perform insertion sort on the array
def insertionsort(n, A):
    for i in range(n):
        for j in range(i):
            if A[i] < A[j]:
                # Swap A[i] and A[j]
                A[i], A[j] = A[j], A[i]
        # Print the array after each insertion
        white(n, A)

# Main function to handle input and call the sorting function
if __name__ == "__main__":
    n = int(input())
    A = list(map(int, input().split()))
    insertionsort(n, A)

# <END-OF-CODE>
