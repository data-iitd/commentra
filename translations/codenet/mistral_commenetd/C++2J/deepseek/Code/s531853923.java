public class Main {
    public static void main(String[] args) {
        // Declare four integer variables to store input values
        int a, b, c, d;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read input values from the user using the Scanner object
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        // Check if the condition is true
        if (a * b % 2 == 1 && (c + d) % 2 == 1) {
            // If the condition is true, print "No" to the output stream
            System.out.println("No");
        } else {
            // If the condition is false, print "Yes" to the output stream
            System.out.println("Yes");
        }
    }
}
