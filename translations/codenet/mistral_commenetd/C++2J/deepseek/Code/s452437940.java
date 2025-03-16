public class Main {
    public static void main(String[] args) {
        // Declare variables
        long a, b, x;

        // Read input values from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextLong();
        b = scanner.nextLong();
        x = scanner.nextLong();

        // Calculate the difference between the number of complete x-blocks in b and a
        long s = (b / x - a / x);

        // If a is a multiple of x, then the last x-block in a is complete, so add 1 to the result
        if (a % x == 0) s++;

        // Print the result to standard output
        System.out.println(s);

        // End of main function
    }
}
