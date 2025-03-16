# Importing the Scanner class from the java.util package
import sys

# Main method is the entry point of the Python application
def main():
    # Reading the values of pandu, vundu and urdu from the console using sys.stdin
    pandu = int(sys.stdin.readline().strip())
    vundu = int(sys.stdin.readline().strip())
    urdu = int(sys.stdin.readline().strip())

    # Initializing the variable c to 0
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

# Calling the main method
if __name__ == "__main__":
    main()
