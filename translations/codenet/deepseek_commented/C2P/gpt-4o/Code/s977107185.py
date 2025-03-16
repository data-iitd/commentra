# Include necessary headers for input-output functions

def main():
    N = int(input())  # Read the size of the array
    A = list(map(int, input().split()))  # Read the elements of the array

    count = 0  # Initialize swap counter

    # Implement Bubble Sort
    for i in range(N - 1):
        for j in range(N - 1, i, -1):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]  # Swap A[j] and A[j-1]
                count += 1  # Increment the swap counter

    print(" ".join(map(str, A)))  # Print the sorted array elements
    print(count)  # Print the number of swaps

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
