
import java.util.Scanner;

public class s178339312{
    public static void main(String[] args) {
        // Declare a variable 'x' of type int to store user input
        int x;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read an integer value from standard input and store it in 'x'
        x = scanner.nextInt();

        // Close the Scanner object to release system resources
        scanner.close();

        // Calculate the cube of 'x' and print the result to standard output
        System.out.println(x * x * x);
    }
}
