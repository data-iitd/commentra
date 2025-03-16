# Importing the Scanner class for reading input from the console
from java.util import Scanner

# Defining the main method as the entry point of the program
def main ( args [ ] ):
    # Creating a new Scanner object to read input from the console
    s = Scanner ( System.in )

    # Reading the number of test cases
    n = s.nextInt ( )

    # Declaring an integer array dp of size 200001 to store the position of each number in the sequence
    dp = [ 0 ] * 200001

    # Initializing a long variable ans to store the answer
    ans = 0

    # Iterating through each test case
    for i in range ( n ):
        # Reading the next number to be added to the sequence
        num = s.nextInt ( )

        # Storing the position of the number in the dp array
        dp [ num ] = i

    # Calculating the answer by iterating through the dp array and finding the absolute difference between the positions of consecutive numbers
    for i in range ( 2, n + 1 ):
        # Adding the absolute difference to the answer
        ans += abs ( dp [ i ] - dp [ i - 1 ] )

    # Printing the answer to the console
    print ( ans )

# End of code
