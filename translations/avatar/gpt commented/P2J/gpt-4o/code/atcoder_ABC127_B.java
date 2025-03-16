import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input values for r, D, and x from the user
        Scanner scanner = new Scanner(System.in);
        int r = scanner.nextInt();
        int D = scanner.nextInt();
        int x = scanner.nextInt();

        // Iterate over a range of values from 2 to 11 (inclusive)
        for (int i = 2; i <= 11; i++) {
            // Calculate and print the result based on the formula
            // The formula computes a value using the current iteration index i,
            // the input values r, D, and x, and prints the integer result
            int result = (int) (Math.pow(r, i - 1) * (x + D / (1.0 - r)) - D / (1.0 - r));
            System.out.println(result);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
