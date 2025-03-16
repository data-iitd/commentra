public class Main {
    public static void main(String[] args) {
        // Declare character arrays to store three strings
        char[] A = new char[20];
        char[] B = new char[20];
        char[] C = new char[20];

        // Read three strings from the user, separated by spaces
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String input = scanner.nextLine();
        String[] parts = input.split(" ");
        A = parts[0].toCharArray();
        B = parts[1].toCharArray();
        C = parts[2].toCharArray();

        // Calculate the lengths of strings A and B
        int la = A.length;
        int lb = B.length;

        // Check if the last character of A matches the first character of B
        // and if the last character of B matches the first character of C
        if (A[la - 1] == B[0] && B[lb - 1] == C[0]) {
            // If both conditions are true, print "YES"
            System.out.println("YES");
        } else {
            // Otherwise, print "NO"
            System.out.println("NO");
        }
    }
}
