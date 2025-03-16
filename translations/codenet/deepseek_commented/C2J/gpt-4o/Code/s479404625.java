import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Declare character arrays to store three strings
        String A, B, C;

        // Read three strings from the user, separated by spaces
        A = scanner.next();
        B = scanner.next();
        C = scanner.next();

        // Calculate the lengths of strings A and B
        int la = A.length();
        int lb = B.length();

        // Check if the last character of A matches the first character of B
        // and if the last character of B matches the first character of C
        if (A.charAt(la - 1) == B.charAt(0) && B.charAt(lb - 1) == C.charAt(0)) {
            // If both conditions are true, print "YES"
            System.out.println("YES");
        } else {
            // Otherwise, print "NO"
            System.out.println("NO");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
