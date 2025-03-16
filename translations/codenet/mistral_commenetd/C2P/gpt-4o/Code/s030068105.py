# The main function is the entry point of the program
def main():
    # Read the number of elements from the user
    n = int(input("Enter the number of elements: "))

    # Allocate memory for the array of size 'n'
    data = []

    # Read each element of the array from the user
    for i in range(n):
        element = int(input(f"Enter element {i + 1}: "))
        data.append(element)

    max_value = 0  # Initialize 'max_value' variable to store the maximum element
    index = -1     # Initialize 'index' variable to store the index of the maximum element

    # Find the maximum element and its index
    for i in range(n):
        if data[i] > max_value:
            max_value = data[i]
            index = i

    a = 0  # Initialize 'a' variable to store the sum of all elements except the maximum

    # Calculate the sum of all elements except the maximum
    for i in range(n):
        if i != index:
            a += data[i]

    # Check if the sum of all elements except the maximum is greater than the maximum
    if a > max_value:
        print("Yes")
    else:
        print("No")

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
