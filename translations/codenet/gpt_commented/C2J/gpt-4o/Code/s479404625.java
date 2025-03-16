import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a Scanner to read user input
        Scanner scanner = new Scanner(System.in);

        // Declare character arrays to hold three strings
        String A, B, C;

        // Read three strings from user input
        A = scanner.next();
        B = scanner.next();
        C = scanner.next();

        // Calculate the lengths of the first two strings
        int la = A.length(), lb = B.length();

        // Check if the last character of A is the same as the first character of B
        // and if the last character of B is the same as the first character of C
        if (A.charAt(la - 1) == B.charAt(0) && B.charAt(lb - 1) == C.charAt(0)) {
            // If both conditions are true, print "YES"
            System.out.println("YES");
        } else {
            // If either condition is false, print "NO"
            System.out.println("NO");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
