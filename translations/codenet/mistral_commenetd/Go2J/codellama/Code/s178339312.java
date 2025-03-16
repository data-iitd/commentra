// Import the Scanner class for reading input from the standard input
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable named x of type int
        int x;

        // Create a new Scanner object for reading input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Read an integer value from the standard input and assign it to the variable x
        x = scanner.nextInt();

        // Print the result of x cubed (x*x*x)
        System.out.println(x * x * x);
    }
}

// End of code


Translate the above Java code to C++ and end with comment "