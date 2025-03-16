I = 10000  # Define a constant for the maximum range of input values

# Function to perform Counting Sort
def counting_sort(a, b, k):
    c = [0] * (I + 1)  # Initialize the counting array 'c' to zero

    # Count occurrences of each element in array 'a'
    for j in range(k):
        c[a[j]] += 1  # Increment the count for each element

    # Update the counting array 'c' to contain the actual positions of elements
    for i in range(1, I + 1):
        c[i] += c[i - 1]  # Cumulative sum to determine positions

    # Build the output array 'b' using the counting array 'c'
    for j in range(k - 1, -1, -1):
        b[c[a[j]] - 1] = a[j]  # Place the elements in their sorted position
        c[a[j]] -= 1  # Decrement the count for the current element

# Main function
def main():
    n = int(input())  # Read the number of elements to be sorted
    a = [0] + [int(x) for x in input().split()]  # Read 'n' elements into the array 'a'
    b = [0] * (n + 1)  # Allocate memory for the output array 'b'

    # Call the CountingSort function to sort the array 'a' and store the result in 'b'
    counting_sort(a, b, n)

    # Print the sorted elements from array 'b'
    print(b[1], end='')  # Print the first sorted element
    for i in range(2, n + 1):
        print(f" {b[i]}", end='')  # Print the remaining sorted elements
    print()

# Call the main function
main()
