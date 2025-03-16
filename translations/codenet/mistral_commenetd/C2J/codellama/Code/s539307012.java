
import java.util.Scanner; // Importing the Scanner class from the java.util package

public class Main { // Defining the Main class
	public static void main(String[] args) { // Defining the main function, which is the starting point of the program
		Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read from the standard input

		int n = sc.nextInt(); // Reading the first integer from the standard input and storing it in the variable n
		int x = sc.nextInt(); // Reading the second integer from the standard input and storing it in the variable x
		int min = sc.nextInt(); // Reading the third integer from the standard input and storing it in the variable min

		x -= min; // Subtracting the minimum value from x

		for (int i = 1; i < n; i++) { // Starting a for loop that iterates from 1 to n-1
			int m = sc.nextInt(); // Reading an integer from the standard input and storing it in the variable m

			x -= m; // Subtracting the current number from x

			if (min > m) { // Checking if the current number is smaller than the current minimum
				min = m; // Updating the minimum if it is
			}
		}

		System.out.println(n + x / min); // Printing the final result, which is the number of elements plus the quotient of the remaining difference and the minimum number

		sc.close(); // Closing the Scanner object
	}
}

