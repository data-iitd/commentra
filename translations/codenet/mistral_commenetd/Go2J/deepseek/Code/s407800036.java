public class Main {
    public static void main(String[] args) {
        // Declare three integer variables named A, B, and C
        int A, B, C;

        // Use the Scanner class to read three integers from the standard input
        // and assign them to the variables A, B, and C respectively
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();

        // Check if the value of C is within the range of A and B
        if (C >= A && C <= B) {
            // If it is, print "Yes" to the standard output
            System.out.println("Yes");
        } else {
            // Otherwise, print "No" to the standard output
            System.out.println("No");
        }

        // End of code
    }
}
