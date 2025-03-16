# Include the iostream library for input and output operations
# Include the standard I/O library for printf and scanf functions
# Include the algorithm library for sorting the array

# The main function is the entry point of the program
def main():
    s = [0]*11 # Declare an integer array's' of size 11
    i = 0      # Declare an integer variable 'i' for loop counter

    # Read 10 integers from the user and store them in the array's'
    for i in range(0,10):
        s[i] = int(input()) # Read an integer from the standard input and store it in the array's' at the current index

    # Sort the array's' in ascending order using the sort function from the algorithm library
    s.sort()

    # Print the 4th, 5th and 6th smallest elements from the sorted array's'
    for i in range(9,6,-1): # Initialize the loop counter 'i' to 9 (index of the 5th smallest element) and decrement it until it becomes greater than the index of the 6th smallest element
        print(s[i]) # Print the current element of the array's' to the standard output

# Execute the main function
if __name__ == "__main__":
    main()

