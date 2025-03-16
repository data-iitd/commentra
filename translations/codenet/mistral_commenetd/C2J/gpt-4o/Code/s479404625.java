import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three character arrays of size 20 each to store strings A, B, and C
        Scanner scanner = new Scanner(System.in);
        String A = scanner.next();
        String B = scanner.next();
        String C = scanner.next();

        // Calculate the length of strings A and B
        int la = A.length();
        int lb = B.length();

        // Logical block to check if the last character of string A is same as the first character of string B
        // and the last character of string B is same as the first character of string C
        if (A.charAt(la - 1) == B.charAt(0) && B.charAt(lb - 1) == C.charAt(0)) {
            // If the condition is true, print YES on the console
            System.out.println("YES");
        } else {
            // If the condition is false, print NO on the console
            System.out.println("NO");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
