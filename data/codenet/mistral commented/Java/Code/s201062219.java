
import java.io.IOException; // Importing the IOException class for handling input/output exceptions
import java.util.Scanner; // Importing the Scanner class for reading user input

public class Main {

	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in); // Creating a new Scanner object to read user input
		String mark; // Declaring a String variable named 'mark' to store the operator symbol
		int c = 0; // Declaring an integer variable named 'c' to store the first number
		int b = 0; // Declaring an integer variable named 'b' to store the second number
		int a[] = new int[100000]; // Declaring and initializing an integer array named 'a' with a size of 100000
		int x = 0; // Declaring and initializing an integer variable named 'x' to keep track of the current index in the array 'a'

		do { // Starting a do-while loop to read user input and perform calculations
			c = scan.nextInt(); // Reading the first number from user input
			mark = scan.next(); // Reading the operator symbol from user input
			b = scan.nextInt(); // Reading the second number from user input

			// Performing calculations based on the operator symbol
			if (mark.equals("?")) { // If the operator symbol is '?'
				a[x] = 2000001; // Setting the current element in the array 'a' to a special value
				break; // Exiting the loop
			} else if (mark.equals("+")) { // If the operator symbol is '+'
				a[x] = c + b; // Adding the first number and the second number and storing the result in the current element of the array 'a'
			} else if (mark.equals("-")) { // If the operator symbol is '-'
				a[x] = c - b; // Subtracting the second number from the first number and storing the result in the current element of the array 'a'
			} else if (mark.equals("*")) { // If the operator symbol is '*'
				a[x] = c * b; // Multiplying the first number and the second number and storing the result in the current element of the array 'a'
			} else if (mark.equals("/")) { // If the operator symbol is '/'
				a[x] = c / b; // Dividing the first number by the second number and storing the result in the current element of the array 'a'
			}
			x++; // Incrementing the index 'x' to move to the next element in the array 'a'
		} while (true); // Looping infinitely until an invalid operator symbol is encountered

		x = 0; // Resetting the index 'x' to the beginning of the array 'a'
		do { // Starting a do-while loop to print the results of the calculations
			if (a[x] == 2000001) { // If the current element in the array 'a' is the special value
				break; // Exiting the loop
			}
			System.out.println(a[x]); // Printing the result of the current calculation
			x++; // Incrementing the index 'x' to move to the next element in the array 'a'
		} while (true); // Looping infinitely until all the valid elements in the array 'a' have been printed

		scan.close(); // Closing the Scanner object to free up system resources
	}
}

