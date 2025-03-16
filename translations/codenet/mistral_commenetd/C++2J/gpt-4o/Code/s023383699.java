import java.util.Scanner;
// Import the Scanner class for taking input from the user.

public class Main {
    public static void main(String[] args) {
        int x;
        // Declare an integer variable x.
        Scanner scanner = new Scanner(System.in);
        // Create a Scanner object to read input from the user.
        x = scanner.nextInt();
        // Use the nextInt method to take an integer input from the user and assign it to the variable x.
        System.out.println(x * x * x);
        // Use the println method to display the result of the computation x*x*x on the console.
        // This will automatically add a newline character to the output.
        scanner.close();
        // Close the scanner to prevent resource leaks.
    }
}
// End of the Main class
