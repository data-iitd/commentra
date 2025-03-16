# Importing the Scanner class from the java.util package
from java.util import Scanner

# Main method is the entry point of the Java application
def main(args):
    # Initializing the Scanner object to read input from the console
    sc = Scanner(System.in)

    # Declaring and initializing variables for pandu, vundu, urdu and counter c
    pandu = 0
    vundu = 0
    urdu = 0
    c = 0

    # Reading the values of pandu, vundu and urdu from the console using Scanner
    pandu = sc.nextLong()
    vundu = sc.nextLong()
    urdu = sc.nextLong()

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

# End of code
