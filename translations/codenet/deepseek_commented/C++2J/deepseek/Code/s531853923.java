public class Main {
    public static void main(String[] args) {
        // Declare four integer variables to store user input
        int a, b, c, d;

        // Read four integers from the standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        // Check if the product of a and b is odd and if the sum of c and d is also odd
        if (a * b % 2 == 1 && (c + d) % 2 == 1) {
            // If both conditions are true, print "No"
            System.out.println("No");
        } else {
            // Otherwise, print "Yes"
            System.out.println("Yes");
        }
    }
}
