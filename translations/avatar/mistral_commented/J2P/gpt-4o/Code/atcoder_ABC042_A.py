# Import sys module for reading input from console
import sys

def main():
    # Read a line of input from the console
    line = sys.stdin.readline().strip()

    # Split the line into a list of strings using space character as delimiter
    list = line.split(" ")

    # Parse the first three elements of the list as integers x, a, and y
    x = int(list[0])
    a = int(list[1])
    y = int(list[2])

    # Initialize a string variable h with the value "NO"
    h = "NO"

    # Check if any of the numbers x, a, or y are equal to 5 or 7
    if x == 5 or x == 7 or a == 5 or a == 7 or y == 5 or y == 7:
        # If any of the numbers satisfy the condition, check if their sum is equal to 17
        if x + y + a == 17:
            # If the sum is equal to 17, set the value of h to "YES"
            h = "YES"

    # Print the value of h to the console
    print(h)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
