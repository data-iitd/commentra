# Python translation of the provided C code

def main():
    n = int(input("Enter the number of elements: "))  # Read the number of elements from the standard input

    a = []  # Initialize an empty list to store the input numbers
    count = [0] * n  # Initialize a list of size n to store the count of occurrences of each number

    print(f"Enter {n} numbers:")
    for i in range(n):  # Initialize the list a with input numbers
        a.append(int(input()))

    print("Initializing count array with zeros:")
    # The count array is already initialized to zeros

    print("Counting occurrences:")
    for i in range(n):  # Iterate through the list a and increment the corresponding element in the count list
        count[a[i] - 1] += 1

    print("Printing the contents of the count array:")
    for i in range(n):  # Print the contents of the count list to the standard output
        print(count[i])

    print("Program completed successfully.")

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
