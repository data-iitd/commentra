# Importing the sys module to read input from the console
import sys

# Main function is the entry point of the Python application
def main():
    # Declaring and initializing variables for pandu, vundu, urdu and counter c
    pandu = int(sys.stdin.readline().strip())
    vundu = int(sys.stdin.readline().strip())
    urdu = int(sys.stdin.readline().strip())
    c = 0

    # Using a for loop to calculate the sum of the series and store it in the variable c
    for i in range(1, urdu + 1):
        c += i * pandu
        # Comment: Calculating the sum of the series using the formula: c = c + i * pandu

    # Checking if the calculated sum is less than vundu
    if c < vundu:
        # Comment: If the calculated sum is less than vundu, then print "0"
        print("0")
    else:
        # Comment: If the calculated sum is greater than or equal to vundu, then print the difference between the calculated sum and vundu
        print(c - vundu)

# Calling the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
