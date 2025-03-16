import java.util.Scanner;

public class Main {
    // Function to count multiples of d in the range [l, r]
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for l, r, and d
        long l = scanner.nextLong();
        long r = scanner.nextLong();
        long d = scanner.nextLong();
        
        // Count the multiples of d in the range [l, r]
        long ans = 0;
        for (long i = l; i <= r; i++) {
            if (i % d == 0) {
                ans++;
            }
        }

        // Output the result
        System.out.println(ans);
        scanner.close();
    }
}
// <END-OF-CODE>
