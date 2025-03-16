public class Main {
    public static void main(String[] args) {
        // Import the Scanner class to read input from the user
        import java.util.Scanner;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Take three integers as input from the user
        int r = scanner.nextInt();
        int D = scanner.nextInt();
        int x = scanner.nextInt();

        // Iterate through the range of numbers from 2 to 11 (12 is excluded)
        for (int i = 2; i < 12; i++) {
            // Calculate the expression and print the integer result
            int result = (int) Math.round(Math.pow(r, i - 1) * (x + D / (1.0 - r)) - D / (1.0 - r));
            System.out.println(result);
        }

        // Close the Scanner object
        scanner.close();
    }
}
