import java.util.Scanner;

public class GCD_LCM {
    
    // Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
    public static long euclid(long x, long y) {
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
        return euclid(y, x % y);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two long long integers from standard input
        long A = scanner.nextLong();
        long B = scanner.nextLong();

        // Calculate and output the least common multiple (LCM) of A and B
        System.out.println((A * B) / euclid(A, B));
        
        scanner.close();
    }
}

// <END-OF-CODE>
