# Import necessary module
import sys

def main():
    sc_list = []  # Create a list to store input lines

    # Continuously read input lines from the user until an exception occurs
    try:
        while True:
            line = input()  # Read a line of input
            sc_list.append(line)  # Add the input line to the list
    except EOFError:
        pass  # Exit the loop if an EOFError occurs

    # Get the first line of input and split it into a list of strings
    numlist = sc_list[0].split(" ")

    # Parse the first element to get the number of sheep
    sheep = int(numlist[0])

    # Parse the second element to get the number of wolves
    wolve = int(numlist[1])

    # Check if the number of wolves is greater than or equal to the number of sheep
    if wolve >= sheep:
        print("unsafe")  # Print "unsafe" if the condition is true
    else:
        print("safe")  # Print "safe" otherwise

if __name__ == "__main__":
    main()

# <END-OF-CODE>
