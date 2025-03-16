# Import necessary libraries
import numpy as np

# Function to perform counting sort algorithm
def counting_sort(a, k):
    # Declare an array 'c' of size I to store the count of occurrences of each element
    I = 10000
    c = np.zeros(I, dtype=int)

    # Count the occurrences of each element in array 'a' and store it in array 'c'
    for j in range(k):
        c[a[j + 1]] += 1

    # Calculate the cumulative sum of all elements in array 'c'
    for i in range(1, I):
        c[i] += c[i - 1]

    # Create an output array 'b' to store the sorted elements
    b = np.zeros(k + 1, dtype=int)

    # Sort the array 'b' by placing each element 'a[j]' at its correct position in array 'b'
    for j in range(k, 0, -1):
        b[c[a[j]]] = a[j]
        c[a[j]] -= 1

    return b

# Main function starts here
def main():
    # Read the number of elements 'n' from the user
    n = int(input("Enter the number of elements: "))

    # Allocate memory for arrays 'a' and 'b' of size (n+1)
    a = np.zeros(n + 1, dtype=int)

    # Read elements of array 'a' from the user
    print(f"Enter {n} integers:")
    max_value = 0
    for i in range(n):
        a[i + 1] = int(input())
        # Update the maximum element if a new element is greater
        if a[i + 1] > max_value:
            max_value = a[i + 1]

    # Call the counting_sort function to sort the array 'a'
    b = counting_sort(a, n)

    # Print the sorted elements of array 'b'
    print(b[1], end="")
    for i in range(2, n + 1):
        print(f" {b[i]}", end="")
    print()

# Execute the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
