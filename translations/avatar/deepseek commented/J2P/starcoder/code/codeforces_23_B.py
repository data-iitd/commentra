
# Importing the Scanner class for input operations
import java.util.Scanner;

# Defining the Main class
class Main:
    # The main method, the entry point of the program
    def main(self):
        scan = Scanner(System.in); # Creating a Scanner object to read input
        t = scan.nextInt(); # Reading the number of test cases
        for i in range(t): # Looping through each test case
            n = scan.nextInt(); # Reading the value of n for each test case
            print(maxLeft(n)); # Calling the maxLeft method and printing the result

    # Defining the maxLeft method
    def maxLeft(self, n):
        return n > 2? n - 2 : 0; # Returning n - 2 if n is greater than 2, otherwise returning 0

# 