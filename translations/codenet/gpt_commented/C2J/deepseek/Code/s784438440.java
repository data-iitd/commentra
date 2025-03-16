public class Main {
    public static void main(String[] args) {
        // Declare two integer variables a and b
        int a, b;

        // Read two integers from user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate and print the result of the expression
        // The expression computes the number of complete groups of (a-1) that can fit into (b-1) + (a-2)
        System.out.println((b - 1 + a - 2) / (a - 1));

        // Return 0 to indicate successful execution of the program
    }
}
