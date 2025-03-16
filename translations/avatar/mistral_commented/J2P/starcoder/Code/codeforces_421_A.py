# Import necessary classes
import java.math.BigInteger;
import java.nio.charset.IllegalCharsetNameException;
import java.util.ArrayList;
import java.util.Scanner;

# Create the Main class and define the main method
class Main:
    def main(self):
        # Initialize a Scanner object to read input
        sc = Scanner(System.in);

        # Declare and initialize variables
        n, a, b = 0, 0, 0
        n = sc.nextInt(); # Read the number of test cases
        a = sc.nextInt(); # Read the number of elements in the first list
        b = sc.nextInt(); # Read the number of elements in the second list

        # Create ArrayList objects to store the lists
        list1 = ArrayList();
        list2 = ArrayList();

        # Read and store the elements of the first and second lists
        for i in range(a):
            list1.add(sc.nextInt()); # Read and add an element to list1
        for i in range(b):
            list2.add(sc.nextInt()); # Read and add an element to list2

        # Iterate through the input array and print the corresponding number based on the presence of the element in list1
        for i in range(n):
            if list1.contains(i + 1): # Check if the current input element is present in list1
                print(1, end=" "); # If present, print 1
            else:
                print(2, end=" "); # If not present, print 2
        print("