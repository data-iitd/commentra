public class Main {
    public static void main(String[] args) {
        long n, a, m, M, c, b, i; // Declare variables to store input, current number, min, max, sum, and loop index
        c = 0; // Initialize sum to 0
        m = 100000000; // Initialize minimum to a large positive value
        M = -100000000; // Initialize maximum to a large negative value
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextLong(); // Read the number of elements

        // Loop through each element
        for (i = 1; i <= n; i++) {
            a = scanner.nextLong(); // Read the current number
            if (a > M) {
                M = a; // Update maximum if current number is greater
            }
            if (a < m) {
                m = a; // Update minimum if current number is smaller
            }
            c = c + a; // Add current number to sum
        }

        System.out.println(m + " " + M + " " + c); // Print the minimum, maximum, and sum of the numbers
    }
}
