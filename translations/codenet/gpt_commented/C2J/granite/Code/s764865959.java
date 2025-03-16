
import java.util.Scanner;

public class s764865959{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read an integer value from the user and store it in variable x
        int x = scanner.nextInt();

        // Calculate the cube of the input value by multiplying it by itself twice
        x = x * x * x;

        // Print the result (the cube of the input value) to the console
        System.out.println(x);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
