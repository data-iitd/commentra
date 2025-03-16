import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read an integer value for 'n' from the standard input
        int n = scanner.nextInt();

        // Calculate the result as (n - 2) * 180
        int result = (n - 2) * 180;

        // Output the result to the standard output
        System.out.println(result);

        // Close the scanner to free up resources
        scanner.close();
    }
}
