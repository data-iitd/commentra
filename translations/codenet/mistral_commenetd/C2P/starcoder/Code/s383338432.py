# Program to print a rectangle

# Function to print a rectangle
def print_rectangle(height, width):
    # Print top border
    for i in range(width+2):
        print("#", end="")
    print()

    # Print body of rectangle
    for i in range(height):
        # Read a string from the user
        input_str = input()
        # Print top and bottom border of each row
        print("#" + input_str + "#")

    # Print bottom border
    for i in range(width+2):
        print("#", end="")
    print()

# Driver code
if __name__ == "__main__":
    # Declare variables for height and width of the rectangle to be printed
    height = int(input("Enter height of rectangle: "))
    width = int(input("Enter width of rectangle: "))

    # Call the function to print the rectangle
    print_rectangle(height, width)

