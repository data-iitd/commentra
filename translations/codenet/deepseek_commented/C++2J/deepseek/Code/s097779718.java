public class Main {
    // Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
    public static long Euclid(long x, long y) {
        long tmp;

        // Ensure x is greater than y
        if (x < y) {
            tmp = x;
            x = y;
            y = tmp;
        }

        // Base case: if x is divisible by y, return y
        if (x % y == 0) return y;

        // Recursive case: apply the Euclidean algorithm
        return Euclid(y, x % y);
    }

    public static void main(String[] args) {
        long A, B;

        // Read two long integers from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        A = scanner.nextLong();
        B = scanner.nextLong();

        // Calculate and output the least common multiple (LCM) of A and B
        System.out.println((A * B) / Euclid(A, B));
    }
}
