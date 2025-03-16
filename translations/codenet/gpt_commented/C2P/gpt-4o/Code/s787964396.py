def counting_sort(a, n):
    I = 10000  # Define a constant for the maximum range of input values
    c = [0] * (I + 1)  # Initialize the counting array 'c' to zero
    b = [0] * (n + 1)  # Output array

    # Count occurrences of each element in array 'a'
    for j in range(n):
        c[a[j + 1]] += 1  # Increment the count for each element

    # Update the counting array 'c' to contain the actual positions of elements
    for i in range(1, I + 1):
        c[i] += c[i - 1]  # Cumulative sum to determine positions

    # Build the output array 'b' using the counting array 'c'
    for j in range(n, 0, -1):
        b[c[a[j]]] = a[j]  # Place the elements in their sorted position
        c[a[j]] -= 1  # Decrement the count for the current element

    return b

def main():
    n = int(input())  # Read the number of elements to be sorted
    a = [0] * (n + 1)  # Allocate memory for the input array 'a'

    # Read 'n' elements into the array 'a'
    for i in range(n):
        a[i + 1] = int(input())  # Store elements starting from index 1

    # Call the counting_sort function to sort the array 'a'
    b = counting_sort(a, n)

    # Print the sorted elements from array 'b'
    print(b[1], end='')  # Print the first sorted element
    for i in range(2, n + 1):
        print(" ", b[i], end='')  # Print the remaining sorted elements
    print()  # New line at the end

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
