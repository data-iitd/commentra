import java.util.Scanner; // Importing the Scanner class for input

public class Main { // Starting the Main class
    public static void main(String[] args) { // Starting the main method
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input

        while (true) { // Starting an infinite loop
            if (scanner.hasNextInt()) { // Checking if the input is valid and can be read into the variables
                int a = scanner.nextInt(); // Reading the value of a
                int b = scanner.nextInt(); // Reading the value of b
                int c = scanner.nextInt(); // Reading the value of c
                int d = scanner.nextInt(); // Reading the value of d
                int e = scanner.nextInt(); // Reading the value of e
                int f = scanner.nextInt(); // Reading the value of f

                // Input is valid, so process it
                double y = (double) (c * d - f * a) / (b * d - e * a); // Calculating the value of y using the given formula
                double x = (double) (c * e - f * b) / (a * e - d * b); // Calculating the value of x using the given formula
                if (y <= 0.0005) { // Checking if y is less than or equal to a very small positive number
                    y = 0; // If so, set y to 0
                }
                if (x <= 0.0005) { // Checking if x is less than or equal to a very small positive number
                    x = 0; // If so, set x to 0
                }
                System.out.printf("%.3f %.3f\n", x, y); // Printing the values of x and y to the standard output with three decimal places
            } else { // Input is invalid or end of file reached
                break; // Exiting the loop
            }
        }

        scanner.close(); // Closing the Scanner object
    }
}
