I = 10000  # Define a constant I with the value 10000

# Function to perform Counting Sort
def counting_sort(a, b, k):
    c = [0] * (I + 1)
    
    # Count the occurrences of each element in array a
    for j in range(k):
        c[a[j + 1]] += 1
    
    # Compute the cumulative count to determine the positions of elements in the sorted array
    for i in range(1, I + 1):
        c[i] += c[i - 1]
    
    # Place elements into array b in sorted order
    for j in range(k, 0, -1):
        b[c[a[j]]] = a[j]
        c[a[j]] -= 1

# Main function
def main():
    n = int(input())  # Read the number of elements
    a = [0] * (n + 1)  # Dynamically allocate memory for array a
    b = [0] * (n + 1)  # Dynamically allocate memory for array b
    
    # Read elements into array a starting from index 1 to n
    for i in range(n):
        a[i + 1] = int(input())
    
    # Call CountingSort function to sort the array
    counting_sort(a, b, n)
    
    # Print the sorted elements starting from index 1 to n
    print(b[1], end='')
    for i in range(2, n + 1):
        print(f" {b[i]}", end='')
    print()

# Call the main function
if __name__ == "__main__":
    main()
