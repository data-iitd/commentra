public class Main {
    public static void main(String[] args) {
        // Read input A, B, and C
        int A = readInt();
        int B = readInt();
        int C = readInt();

        // Check if C is within the range of A and B
        if (C >= A && C <= B) {
            System.out.println("Yes"); // Print "Yes" if condition is true
        } else {
            System.out.println("No");  // Print "No" if condition is false
        }
    }

    // Helper functions for reading input
    public static int readInt() {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        return scanner.nextInt();
    }
}
