# Function to swap the values of two integers
def swap(a, b):
    return b, a  # Return the swapped values

def main():
    while True:  # Infinite loop to continuously read input until termination condition is met
        # Read two integers from user input
        a, b = map(int, input().split())
        
        # Check for the termination condition (both inputs are zero)
        if a == 0 and b == 0:
            break

        # If the second number is less than the first, swap them
        if b < a:
            a, b = swap(a, b)
        
        # Print the sorted values of a and b
        print(a, b)

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
