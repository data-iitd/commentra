public class Main {
    public static void main(String[] args) {
        int n = 1; // Initialize n to 1 (can be modified to read input)
        while (n-- > 0) {
            solve(); // Call the solve function n times
        }
    }

    // Function to solve the problem
    public static void solve() {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Read input value for n
        System.out.println(n == 0 ? 1 : 0); // Output the negation of n (1 if n is zero, 0 if n is non-zero)
    }
}
