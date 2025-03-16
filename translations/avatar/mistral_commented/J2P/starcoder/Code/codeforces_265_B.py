# Import necessary classes for file I/O and collections
import java.io.*;
import java.util.*;

# Define the main method, which is the entry point of the program
def main():
    # Create a Scanner object to read input from the standard input
    scn = Scanner(System.in);

    # Read the first integer n representing the size of the array
    n = scn.nextInt();

    # Create an integer array arr of size n
    arr = [0] * n;

    # Use a for loop to read n integers from the standard input and store them in the array arr
    for i in range(0, n):
        arr[i] = scn.nextInt(); # Read the next integer and store it in the current index of the array

    # Initialize a variable ans with the first element of the array and add 1 to it
    ans = arr[0] + 1;

    # Use another for loop to iterate through the remaining elements of the array arr
    for i in range(1, n):
        # Calculate the absolute difference between the current and previous elements and add it to the variable ans along with 2
        ans += abs(arr[i] - arr[i - 1]) + 2;

    # Finally, print the value of ans to the standard output
    print(ans);

# Call the main method
if __name__ == "__main__":
    main();

