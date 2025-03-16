import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read three integers from input: r, D, and x
        int r = scanner.nextInt();
        int D = scanner.nextInt();
        int x = scanner.nextInt();

        // Perform calculations and print the result for 10 iterations
        for (int i = 1; i <= 10; i++) {
            x = r * x - D; // Update x based on the formula
            System.out.println(x); // Print the current value of x
        }
    }
}
