public class Main {
    public static void main(String[] args) {
        // Declare variables to hold two integers and intermediate results
        int a, b, x, w;

        // Continuously read pairs of integers until EOF (End of File) is reached
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextInt()) {
            // Read the two integers
            a = scanner.nextInt();
            b = scanner.nextInt();

            // Calculate the sum of the two integers
            x = a + b;

            // Initialize a counter for the number of digits in the sum
            w = 0;

            // Count the number of digits in the sum (x)
            while (x != 0) {
                // Increment the digit counter
                w++;
                // Remove the last digit from x by dividing by 10
                x /= 10;
            }

            // Print the number of digits in the sum
            System.out.println(w);
        }

        // Close the scanner
        scanner.close();
    }
}
