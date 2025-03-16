
import java.util.Scanner;

public class s934757053{
    public static void main(String[] args) {
        // Declare variables A and B to hold input values
        int A, B;
        // Initialize ans to count the number of iterations
        int ans = 0;
        // Initialize out to 1, which will be used in the loop
        int out = 1;

        // Create a Scanner object to read input values from the user
        Scanner scanner = new Scanner(System.in);

        // Read input values for A and B from the user
        A = scanner.nextInt();
        B = scanner.nextInt();

        // Loop until out is less than B
        while (out < B) {
            // Decrement out by 1
            out--;
            // Increment out by the value of A
            out += A;
            // Increment the answer counter for each iteration
            ans++;
        }

        // Output the final count of iterations
        System.out.println(ans);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
