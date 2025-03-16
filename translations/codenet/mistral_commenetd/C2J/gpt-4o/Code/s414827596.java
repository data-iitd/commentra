import java.util.Scanner; // Importing the Scanner class for input

public class Main { // Defining the Main class
    public static void main(String[] args) { // Starting the main method
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input
        int a, b, c, d, e, f; // Declaring variables a to f as integers
        double x, y; // Declaring variables x and y as double precision floating point numbers

        while (true) { // Starting an infinite loop
            if (scanner.hasNextInt()) { // Checking if the next input is an integer
                a = scanner.nextInt(); // Reading the first integer
                b = scanner.nextInt(); // Reading the second integer
                c = scanner.nextInt(); // Reading the third integer
                d = scanner.nextInt(); // Reading the fourth integer
                e = scanner.nextInt(); // Reading the fifth integer
                f = scanner.nextInt(); // Reading the sixth integer

                // Input is valid, so process it
                y = (double) (c * d - f * a) / (b * d - e * a); // Calculating the value of y using the given formula
                x = (double) (c * e - f * b) / (a * e - d * b); // Calculating the value of x using the given formula
                
                if (y <= 0.0005) { // Checking if y is less than or equal to a very small positive number
                    y = 0; // If so, set y to 0
                }
                if (x <= 0.0005) { // Checking if x is less than or equal to a very small positive number
                    x = 0; // If so, set x to 0
                }
                System.out.printf("%.3f %.3f%n", x, y); // Printing the values of x and y to the standard output with three decimal places
            } else { // Input is invalid or end of file reached
                break; // Exiting the loop
            }
        }
        scanner.close(); // Closing the scanner
    } // Ending the main method
} // Ending the Main class
// <END-OF-CODE>
