import java.util.Scanner;

public class Main {
    // Declare arrays to store input values, prefix sums, and suffix sums
    static long[] a = new long[200005];
    static long[] pre = new long[200005];
    static long[] last = new long[200005];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        
        // Read the input values into the array 'a'
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextLong();
        }

        long sumpre = 0, sumlast = 0;

        // Calculate prefix sums and store them in 'pre' array
        for (int i = 1; i < n; i++) {
            sumpre += a[i];
            pre[i] = sumpre;
            // Debugging output for prefix sums (commented out)
            // System.out.println(pre[i] + "++");
        }

        // Calculate suffix sums and store them in 'last' array
        for (int i = n; i > 1; i--) {
            sumlast += a[i];
            last[i] = sumlast;
            // Debugging output for suffix sums (commented out)
            // System.out.println(last[i] + "+++");
        }

        // Initialize 'd' to a large value to find the minimum difference
        long d = Long.MAX_VALUE;

        // Calculate the minimum absolute difference between prefix and suffix sums
        for (int i = 1; i < n; i++) {
            // Debugging output for the difference calculation (commented out)
            // System.out.println(pre[i] - last[i + 1]);
            d = Math.min(d, Math.abs(pre[i] - last[i + 1]));
        }

        // Output the minimum difference found
        System.out.println(d);
        
        scanner.close();
    }
}

// <END-OF-CODE>
