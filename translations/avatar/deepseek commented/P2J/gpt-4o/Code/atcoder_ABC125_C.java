import java.util.Scanner;

public class GCDArray {

    // Method to calculate the greatest common divisor (GCD) of a and b
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static int[] ruiseki_lr(int[] array) {
        int n = array.length;
        int[] left = new int[n + 1];
        int[] right = new int[n + 1];

        // Compute prefix GCD array
        for (int i = 0; i < n; i++) {
            left[i + 1] = gcd(left[i], array[i]);
        }

        // Compute suffix GCD array
        for (int i = n - 1; i >= 0; i--) {
            right[i] = gcd(right[i + 1], array[i]);
        }

        return new int[][]{left, right};
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        int[] a = new int[n];
        
        // Read the list of elements
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Compute prefix and suffix GCD arrays
        int[][] lr = ruiseki_lr(a);
        int[] left = lr[0];
        int[] right = lr[1];
        
        // Initialize the answer variable
        int ans = 0;
        
        // Iterate through the array to find the maximum GCD
        for (int i = 0; i < n; i++) {
            ans = Math.max(gcd(left[i], right[i + 1]), ans);
        }
        
        // Print the result
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
