import java.util.Scanner;

// This is the main class where the program starts execution
public class Main {
    public static void main(String[] args) {
        int x; // Declare an integer variable named x

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Ask the user to input an integer value and read it into the variable x
        x = scanner.nextInt();

        // Calculate the result of x cubed and print it to the console
        System.out.println(x * x * x);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
