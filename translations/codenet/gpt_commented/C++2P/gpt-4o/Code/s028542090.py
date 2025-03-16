# Declare an array to hold the input values
a = [0] * 100100

def main():
    k = int(input())  # Read the number of elements

    # Read the input values into the array
    for i in range(k):
        a[i] = int(input())

    # Initialize max and min values
    max_val = 3
    min_val = 2

    # Check if the last element is not equal to 2
    if a[k - 1] != 2:
        print(-1)  # Output -1 if the condition is met
        return  # Exit the program

    # Iterate through the array from the second last element to the first
    for i in range(k - 2, -1, -1):
        # If the current element is greater than max, output -1
        if a[i] > max_val:
            print(-1)  # Output -1 if the condition is met
            return  # Exit the program
        else:
            # Update max based on the current element
            max_val = ((max_val // a[i]) + 1) * a[i] - 1
            # Adjust min to be a multiple of the current element if necessary
            if min_val % a[i] != 0:
                min_val = ((min_val // a[i]) + 1) * a[i]

        # Check if the updated max is less than or equal to min
        if max_val <= min_val:
            print(-1)  # Output -1 if the condition is met
            return  # Exit the program

    # Output the final min and max values
    print(min_val, max_val)

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
