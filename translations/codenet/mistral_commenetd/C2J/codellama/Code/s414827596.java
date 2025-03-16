
import java.util.Scanner; // Importing the Scanner class from the java.util package

public class Main { // Starting the Main class
	public static void main(String[] args) { // Starting the main function
		Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read from the standard input
		int a, b, c, d, e, f; // Declaring variables a to f as integers
		double x, y; // Declaring variables x and y as double precision floating point numbers

		while(true) { // Starting an infinite loop
			if(sc.hasNextInt()) { // Checking if the next input is an integer
				a = sc.nextInt(); // Reading the next integer into variable a
				b = sc.nextInt(); // Reading the next integer into variable b
				c = sc.nextInt(); // Reading the next integer into variable c
				d = sc.nextInt(); // Reading the next integer into variable d
				e = sc.nextInt(); // Reading the next integer into variable e
				f = sc.nextInt(); // Reading the next integer into variable f
				y = (double)(c*d-f*a)/(b*d-e*a); // Calculating the value of y using the given formula
				x = (double)(c*e-f*b)/(a*e-d*b); // Calculating the value of x using the given formula
				if(y <= 0.0005) { // Checking if y is less than or equal to a very small positive number
					y = 0; // If so, set y to 0
				}
				if(x <= 0.0005) { // Checking if x is less than or equal to a very small positive number
					x = 0; // If so, set x to 0
				}
				System.out.printf("%.3f %.3f\n",x,y); // Printing the values of x and y to the standard output with three decimal places
			} else { // Input is invalid or end of file reached
				break; // Exiting the loop
			}
		}
	}
}

