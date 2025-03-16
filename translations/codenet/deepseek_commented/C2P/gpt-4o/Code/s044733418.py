import sys  # Import the sys module for input handling

# Define a function to compare two integers
def compare(a, b):
    return b - a  # Return the difference between the two integers

def main():
    array = []  # Initialize an empty list to store integers
    for _ in range(10):  # Read 10 integers from the input
        array.append(int(sys.stdin.readline().strip()))  # Read and convert input to integer
    array.sort(key=lambda x: -x)  # Sort the array in descending order
    for i in range(3):  # Print the first three elements of the sorted array
        print(array[i])

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
