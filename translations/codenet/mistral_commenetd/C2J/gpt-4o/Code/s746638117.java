import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Defining the Main class
    public static void main(String[] args) { // The main method is the entry point of the program
        int a, b, ar, le; // Declaring variables a, b, ar (result of multiplication), and le (result of addition and multiplication by 2)

        Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input
        a = scanner.nextInt(); // Reading the first integer from the user and storing it in variable a
        b = scanner.nextInt(); // Reading the second integer from the user and storing it in variable b

        ar = a * b; // Multiplying the values of variables a and b and storing the result in variable ar
        le = 2 * (a + b); // Multiplying the sum of variables a and b by 2 and storing the result in variable le

        System.out.println(ar + " " + le); // Printing the values of variables ar and le to the console

        scanner.close(); // Closing the scanner to prevent resource leaks
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
