# Python implementation of the Selection Sort algorithm

def main():
    A = [0] * 100  # An array of integers with a maximum size of 100
    n = int(input("Enter the number of elements: "))  # Read the number of elements from the standard input

    print(f"Enter {n} integers:")
    for i in range(n):  # Read n integers from the standard input and store them in the array A
        A[i] = int(input())

    print("Sorting the array using Selection Sort algorithm:")
    sw = 0  # Variable to count the number of swaps
    for i in range(n):  # The outer loop runs n times
        mini = i  # Initialize mini as i
        for j in range(i, n):  # The inner loop finds the minimum element in the unsorted part of the array
            if A[j] < A[mini]:  # If A[j] is smaller than A[mini], update mini
                mini = j
        # Swap A[i] with the minimum element
        A[i], A[mini] = A[mini], A[i]

        if i != mini:  # Increment sw only if a swap is made
            sw += 1

    print("Sorted array:", end=" ")
    for i in range(n):  # Print the sorted array to the standard output
        if i > 0:
            print(" ", end="")
        print(A[i], end="")
    print()

    print(f"Number of swaps: {sw}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
