public class Main {
    public static void main(String[] args) {
        // Declare three long variables to hold input values
        long a, b, c;

        // Read three long integers from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextLong();
        b = scanner.nextLong();
        c = scanner.nextLong();

        // Calculate the value of d as the difference between c and the sum of a and b
        long d = c - a - b;

        // Check if d is positive and if 4 times the product of a and b is less than d squared
        if ((d > 0) && ((4 * a * b) < d * d)) {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No"
            System.out.println("No");
        }

        // Return 0 to indicate successful completion of the program
    }
}
