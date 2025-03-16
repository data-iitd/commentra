import sys

def compare(a, b):
    # Function to compare two integers for sorting
    return b - a

def main():
    array = []  # Initialize an empty list to store integers

    for i in range(10):  # Iterate to read 10 integers
        num = int(input())  # Read an integer from the user
        array.append(num)  # Append the integer to the list

    array.sort(key=lambda x: -x)  # Sort the array in descending order

    for i in range(3):  # Iterate through the first three elements of the sorted array
        print(array[i])  # Print the first three sorted integers

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
