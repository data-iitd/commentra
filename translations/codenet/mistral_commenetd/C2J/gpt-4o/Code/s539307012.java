import java.util.Scanner; // Importing the Scanner class for input

public class Main { // Defining the Main class
    public static void main(String[] args) { // The main method, which is the starting point of the program
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input
        int n, x, min, m; // Declaring the variables n, x, min, and m

        n = scanner.nextInt(); // Reading the first integer and storing it in n
        x = scanner.nextInt(); // Reading the second integer and storing it in x
        min = scanner.nextInt(); // Reading the third integer and storing it in min

        x -= min; // Subtracting the minimum value from x

        for (int i = 1; i < n; i++) { // Starting a for loop that iterates from 1 to n-1
            m = scanner.nextInt(); // Reading an integer from the input and storing it in m

            x -= m; // Subtracting the current number from x

            if (min > m) { // Checking if the current number is smaller than the current minimum
                min = m; // Updating the minimum if it is
            }
        }

        System.out.println(n + x / min); // Printing the final result
        scanner.close(); // Closing the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
