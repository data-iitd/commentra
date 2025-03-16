import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
        // Declare variables
        int n;
        long m;

        // Initialize variables
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        // Assign the value of n to m for later use
        m = n;

        // Decrement n by 1
        n--;

        // Loop through n-1 times to calculate the factorial
        for (; n > 1; n--) {
            // Multiply m with current value of n
            m *= n;
        }

        // Print the result
        System.out.println(m);

        // Return 0 to indicate successful execution
        return 0;
    }
}
