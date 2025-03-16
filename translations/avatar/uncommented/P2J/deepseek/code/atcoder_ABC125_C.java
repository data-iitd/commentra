import java.util.Scanner;

public class Main {
    // Function to calculate the greatest common divisor
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // Function to calculate the prefix and suffix GCD arrays
    public static int[][] ruisekiLR(int[] array) {
        int n = array.length;
        int[][] result = new int[2][n + 1];
        result[0][0] = 0; // Initialize left array
        result[1][n] = 0; // Initialize right array

        // Calculate prefix GCD array
        for (int i = 0; i < n; i++) {
            result[0][i + 1] = gcd(result[0][i], array[i]);
        }

        // Calculate suffix GCD array
        for (int i = n - 1; i >= 0; i--) {
            result[1][i] = gcd(result[1][i + 1], array[i]);
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        scanner.close();

        int[][] result = ruisekiLR(a);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(gcd(result[0][i], result[1][i + 1]), ans);
        }
        System.out.println(ans);
    }
}
