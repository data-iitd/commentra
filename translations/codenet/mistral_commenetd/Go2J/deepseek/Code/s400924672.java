public class Main {
    public static void main(String[] args) {
        // Declaring variables r, D, and x of type int
        int r, D, x;

        // Creating a Scanner object to read input values
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Reading input values for r, D, and x from the standard input
        r = scanner.nextInt();
        D = scanner.nextInt();
        x = scanner.nextInt();

        // Loop runs 10 times
        for (int i = 1; i <= 10; i++) {
            // Print the result of the current iteration
            System.out.println(r * x - D);

            // Update the value of x for the next iteration
            x = r * x - D;
        }
    }
}
