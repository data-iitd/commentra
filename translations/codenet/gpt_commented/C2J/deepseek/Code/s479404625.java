public class Main {
    public static void main(String[] args) {
        // Declare character arrays to hold three strings
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String A = scanner.next();
        String B = scanner.next();
        String C = scanner.next();

        // Calculate the lengths of the first two strings
        int la = A.length();
        int lb = B.length();

        // Check if the last character of A is the same as the first character of B
        // and if the last character of B is the same as the first character of C
        if (A.charAt(la - 1) == B.charAt(0) && B.charAt(lb - 1) == C.charAt(0)) {
            // If both conditions are true, print "YES"
            System.out.println("YES");
        } else {
            // If either condition is false, print "NO"
            System.out.println("NO");
        }
    }
}
