public class Main {
    // Function to compute the greatest common divisor (GCD) of two integers
    public static int gcd(int a, int b) {
        // Ensure 'a' is the larger number for the algorithm
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int r;
        // Apply the Euclidean algorithm to find the GCD
        while ((r = a % b) > 0) {
            a = b; // Update 'a' to 'b'
            b = r; // Update 'b' to the remainder
        }
        return b; // Return the GCD
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Variable to store the number of integers
        int ans = scanner.nextInt(); // Read the first integer and initialize 'ans' with it

        // Loop through the remaining integers to compute the GCD
        for (int i = 1; i < n; ++i) {
            int a = scanner.nextInt(); // Variable to store the current integer
            ans = gcd(ans, a); // Update 'ans' with the GCD of 'ans' and 'a'
        }

        // Output the final GCD result
        System.out.println(ans);
    }
}
