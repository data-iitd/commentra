public class Main {
    public static void main(String[] args) {
        int i, j, k, n; // Declare integer variables i, j, k, and n
        
        // Read an integer input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        
        // Calculate and print the result based on the input n
        // The expression (24 + (24 - n)) simplifies to (48 - n)
        System.out.println(24 + (24 - n));
    }
}
