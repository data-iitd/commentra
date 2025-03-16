import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input values from the standard input
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        int K = scanner.nextInt();

        // Check if the sum of A and B is greater than or equal to K
        if (A + B >= K) {
            // If true, print the minimum value between A and K
            System.out.println(Math.min(A, K));
        } else {
            // If false, calculate the difference between K and the sum of A and B,
            // and subtract it from A to get the required value
            System.out.println(A - (K - (A + B)));
        }
    }
}
