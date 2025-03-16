import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        // Taking input for two integers, `n` and `m`

        if (n < 1) {
            // Check if `n` is less than 1
            if (m < 1) {
                // Check if `m` is also less than 1
                System.out.println(n + " " + m);
                return;
                // Print `n` and `m` and then quit the program
            }
            System.out.println("Impossible");
            return;
            // Print "Impossible" and then quit the program
        }

        if (m > n) {
            // Check if `m` is greater than `n`
            int min = m;
            int max = n + m - 1;
            System.out.println(min + " " + max);
            // Calculate `min` as `m` and `max` as `n + m - 1`, then print `min` and `max`
        }

        if (m <= n) {
            // Check if `m` is less than or equal to `n`
            int min = n;
            int max = n + m - 1;
            if (m == 0) {
                max = n;
            }
            System.out.println(min + " " + max);
            // Calculate `min` as `n` and `max` as `n + m - 1`. If `m` is 0, set `max` to `n`. Finally, print `min` and `max`
        }
    }
}
// <END-OF-CODE>
