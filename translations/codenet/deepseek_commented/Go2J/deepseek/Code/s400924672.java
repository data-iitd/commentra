public class Main {
    public static void main(String[] args) {
        // Declare integer variables for radius, D, and x
        int r, D, x;

        // Read three integers from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        r = scanner.nextInt();
        D = scanner.nextInt();
        x = scanner.nextInt();

        // Loop 10 times
        for (int i = 1; i <= 10; i++) {
            // Print the result of the calculation
            System.out.println(r * x - D);
            // Update x for the next iteration
            x = r * x - D;
        }
    }
}
