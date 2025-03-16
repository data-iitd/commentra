# Declare the main function
def main():
    # Declare and initialize an integer variable 'n'
    n = int(input("Enter the number of elements in the array: "))  # Read the number of elements in the array from the user

    # Declare an integer list 'a' of size 'n'
    a = []

    # Read the elements of the array from the user
    print(f"Enter {n} integers:")
    for i in range(n):
        element = int(input(f"Enter element number {i + 1}: "))  # Read an integer value and store it in the list 'a'
        a.append(element)

    # Initialize the sum variable
    sum_diff = 0

    # Calculate the sum of the differences between adjacent elements in the array
    for i in range(1, n):
        # Check if the previous element is greater than the current element
        if a[i - 1] > a[i]:
            # If true, add the difference to the sum
            sum_diff += a[i - 1] - a[i]
            # Swap the elements to maintain the array in non-decreasing order
            a[i] = a[i - 1]

    # Print the sum of the differences
    print(f"The sum of the differences is: {sum_diff}")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
