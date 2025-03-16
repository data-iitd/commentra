
import sys

# Define a constant for the maximum range of input values
I = 10000

# Function to perform Counting Sort
def CountingSort(a, b, k):
    c = [0] * (I + 1)  # Initialize the counting array 'c' to zero
    for j in range(k):
        c[a[j + 1]] += 1  # Count occurrences of each element in array 'a'
    for i in range(1, I + 1):
        c[i] += c[i - 1]  # Update the counting array 'c' to contain the actual positions of elements
    for j in range(k - 1, -1, -1):
        b[c[a[j]]] = a[j]  # Build the output array 'b' using the counting array 'c'
        c[a[j]] -= 1  # Decrement the count for the current element

# Main function
def main():
    n = int(input("Enter the number of elements to be sorted: "))  # Read the number of elements to be sorted
    a = [0] * (n + 1)  # Allocate memory for the input array 'a' and output array 'b'
    b = [0] * (n + 1)
    for i in range(n):
        a[i + 1] = int(input(f"Enter element {i + 1}: "))  # Read 'n' elements into the array 'a'
    CountingSort(a, b, n)  # Call the CountingSort function to sort the array 'a' and store the result in 'b'
    print("Sorted elements:", end=" ")  # Print the sorted elements from array 'b'
    for i in range(1, n + 1):
        print(b[i], end=" ")
    print()

# Call the main function
if __name__ == "__main__":
    main()

