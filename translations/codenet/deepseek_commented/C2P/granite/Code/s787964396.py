
# Python code to perform Counting Sort

# Function to perform Counting Sort
def CountingSort(a, b, k):
    c = [0] * (I + 1)  # Initialize array c to store the count of each element
    for j in range(k):  # Count the occurrences of each element in array a
        c[a[j + 1]] += 1
    for i in range(1, I + 1):  # Compute the cumulative count to determine the positions of elements in the sorted array
        c[i] += c[i - 1]
    for j in range(k, 0, -1):  # Place elements into array b in sorted order
        b[c[a[j]]] - 1] = a[j]
        c[a[j]] -= 1

# Main function
def main():
    n = int(input("Enter the number of elements: "))  # Read the number of elements
    a = [0] * (n + 1)  # Dynamically allocate memory for arrays a and b
    b = [0] * (n + 1)
    for i in range(n):  # Read elements into array a starting from index 1 to n
        a[i + 1] = int(input("Enter element " + str(i + 1) + ": "))
    CountingSort(a, b, n)  # Call CountingSort function to sort the array
    print("Sorted elements:", end=" ")  # Print the sorted elements starting from index 1 to n
    for i in range(1, n + 1):
        print(b[i], end=" ")
    print()

if __name__ == "__main__":
    main()

