# The main function is the entry point of the program
def main():
    # Read the length of the array from the user
    len_array = int(input("Enter the length of the array: "))

    # Read the elements of the array from the user
    a = list(map(int, input(f"Enter {len_array} integers: ").split()))

    # Sort the array using insertion sort algorithm
    for j in range(1, len_array):
        # Print the current state of the array
        print(" ".join(map(str, a)))

        # Set the current key to the next element
        key = a[j]

        # Swap the current key with the previous element if it is greater
        i = j - 1
        while i >= 0 and a[i] > key:
            a[i + 1] = a[i]
            i -= 1

        # Place the current key in its correct position
        a[i + 1] = key

    # Print the sorted array
    print(" ".join(map(str, a)))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
