import java.util.Scanner; // Importing the Scanner class for input

public class Main { // Defining the Main class
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input

        int x; // Declaring an integer variable named x
        x = scanner.nextInt(); // Reading an integer value from the standard input and storing it in the variable x

        if (x == 0) {
            System.out.println("1"); // If the value of x is 0, then print the value 1 followed by a newline
        }
        if (x == 1) {
            System.out.println("0"); // If the value of x is 1, then print the value 0 followed by a newline
        }

        scanner.close(); // Closing the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
