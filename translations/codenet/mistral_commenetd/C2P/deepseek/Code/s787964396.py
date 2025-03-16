def counting_sort(a, b, k):
    # Declare an array 'c' of size I to store the count of occurrences of each element
    c = [0] * (I + 1)

    # Count the occurrences of each element in array 'a' and store it in array 'c'
    for j in range(k):
        c[a[j+1]] += 1

    # Calculate the cumulative sum of all elements in array 'c'
    for i in range(1, I + 1):
        c[i] += c[i - 1]

    # Sort the array 'b' by placing each element 'a[j]' at its correct position in array 'b'
    for j in range(k, 0, -1):
        b[c[a[j]]] = a[j]
        c[a[j]] -= 1

def main():
    # Declare pointers 'a' and 'b' of integer type and allocate memory for them
    n = int(input("Enter the number of elements: "))
    a = [0] * (n + 1)
    b = [0] * (n + 1)

    # Read elements of array 'a' from the user
    print("Enter {} integers:".format(n))
    for i in range(n):
        a[i + 1] = int(input())

    # Call the CountingSort function to sort the array 'a' using counting sort algorithm
    counting_sort(a, b, n)

    # Print the sorted elements of array 'b'
    print(b[1], end='')
    for i in range(2, n + 1):
        print(" {}".format(b[i]), end='')
    print()

# Main function starts here
if __name__ == "__main__":
    main()
# Main function ends here
