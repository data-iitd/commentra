
import java.util.Scanner;

public class s792612560{
    public static void main(String[] args) {
        // Declare an integer variable 'n' for input and an unsigned long long int'm' for storing the result
        int n;
        long m;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read an integer value from the user and store it in 'n'
        n = scanner.nextInt();

        // Initialize'm' with the value of 'n'
        m = n;

        // Decrease 'n' by 1 to prepare for the factorial calculation
        n--;

        // Loop to calculate the factorial of 'n' (m = n!)
        for (; n > 1; n--) {
            // Multiply'm' by the current value of 'n'
            m *= n;
        }

        // Print the calculated factorial value stored in'm'
        System.out.println(m);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
