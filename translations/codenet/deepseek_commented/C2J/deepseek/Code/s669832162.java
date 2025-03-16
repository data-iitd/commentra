public class Main {
    public static void main(String[] args) {
        int m1, d1, m2, d2; // Declare four integer variables to store month and day values
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a Scanner object to read input
        m1 = scanner.nextInt(); // Read the first integer value from the standard input
        d1 = scanner.nextInt(); // Read the second integer value from the standard input
        m2 = scanner.nextInt(); // Read the third integer value from the standard input
        d2 = scanner.nextInt(); // Read the fourth integer value from the standard input
        if (m1 != m2) System.out.println("1"); // Check if the values of m1 and m2 are not equal, if true print 1
        else System.out.println("0"); // If m1 and m2 are equal, print 0
    }
}
