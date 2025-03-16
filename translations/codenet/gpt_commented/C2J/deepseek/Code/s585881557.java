public class Main {
    public static void main(String[] args) {
        // Declare two integer variables h and r
        int h, r;

        // Create a Scanner object to read input from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read two integers from standard input
        h = scanner.nextInt();
        r = scanner.nextInt();

        // Compare the value of r with -h
        if (r > -h) {
            // If r is greater than -h, print "1"
            System.out.println("1");
        } else if (r == -h) {
            // If r is equal to -h, print "0"
            System.out.println("0");
        } else {
            // If r is less than -h, print "-1"
            System.out.println("-1");
        }

        // Close the scanner to free up resources
        scanner.close();
    }
}
