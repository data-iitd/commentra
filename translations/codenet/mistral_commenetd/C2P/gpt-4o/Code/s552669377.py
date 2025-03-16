# Include the standard input/output library

def main():
    # Function main starts the execution of the program
    n = int(input("Enter the number of integers: "))  # Read the number of integers to be entered from the user
    min_val = 1000000  # Initialize variables min
    max_val = -1000000  # Initialize variables max
    total_sum = 0  # Initialize variables sum

    for _ in range(n):
        # Use a for loop to read and process each integer
        tmp = int(input())  # Read the next integer from the user and store it in variable tmp
        if min_val > tmp:
            min_val = tmp  # If the current integer is smaller than the current minimum, update the minimum
        if max_val < tmp:
            max_val = tmp  # If the current integer is larger than the current maximum, update the maximum
        total_sum += tmp  # Add the current integer to the sum

    print(min_val, max_val, total_sum)  # Print the minimum, maximum, and sum of the entered integers

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
