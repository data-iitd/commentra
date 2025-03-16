public class SumCheck {
    public static void main(String[] args) {
        int a, b, c; // Declare three integer variables to hold the input values

        // Read three integers from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Check if any two of the three numbers sum up to the third number
        // If a + b equals c, or b + c equals a, or a + c equals b, print "Yes"
        // Otherwise, print "No"
        System.out.println((a + b == c || b + c == a || a + c == b) ? "Yes" : "No");
    }
}
