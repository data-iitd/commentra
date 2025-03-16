import java.util.Scanner; // Importing the Scanner class for input

public class Main { // Defining the Main class
    public static void main(String[] args) { // Starting the main method
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input
        int a, b, c; // Declaring three integer variables a, b, and c
        a = scanner.nextInt(); // Reading the first integer
        b = scanner.nextInt(); // Reading the second integer
        c = scanner.nextInt(); // Reading the third integer

        if (a < b && b < c) { // Starting the if condition block
            System.out.println("Yes"); // If the condition is true, print "Yes"
        } else { // Starting the else condition block
            System.out.println("No"); // If the condition is false, print "No"
        }

        scanner.close(); // Closing the scanner
    } // Ending the main method
} // Ending the Main class
// <END-OF-CODE>
