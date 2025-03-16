
import java.util.Scanner;

public class s855845406{
    public static void main(String[] args) {
        // Create a Scanner object to read input from standard input
        Scanner scanner = new Scanner(System.in);

        // Read an integer value for N from standard input
        int N = scanner.nextInt();

        // Read an integer value for A from standard input
        int A = scanner.nextInt();

        // Calculate the result by squaring N and subtracting A, then output the result
        System.out.println(N * N - A);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
