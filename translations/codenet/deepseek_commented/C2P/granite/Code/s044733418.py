
import sys  # Import the standard input/output library

# Define a function to compare two integers
def compare(a, b):
    return b - a  # Return the difference between the two integers

def main():  # Define the main function
    array = [int(x) for x in sys.stdin.read().split()]  # Read 10 integers from the input and store them in an array
    array.sort(key=compare)  # Sort the array using the sort method and the compare function
    for i in range(3):  # Print the first three elements of the sorted array
        print(array[i])

if __name__ == "__main__":  # Call the main function if the script is executed directly
    main()

