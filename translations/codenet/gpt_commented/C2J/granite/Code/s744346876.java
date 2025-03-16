
import java.util.Scanner;

public class s744346876{
    public static void main(String[] args) {
        // Declare two integer variables A and B
        int A, B;

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read two integers from user input
        A = scanner.nextInt();
        B = scanner.nextInt();

        // Check if both A and B are less than 10
        if (A < 10 && B < 10) {
            // If both are less than 10, print their product
            System.out.println(A * B);
        } else {
            // If either A or B is 10 or greater, print -1
            System.out.println(-1);
        }

        // Close the Scanner object
        scanner.close();
    }
}
