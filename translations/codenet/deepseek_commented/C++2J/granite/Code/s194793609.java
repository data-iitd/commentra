
import java.util.Scanner;

public class s194793609{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // 1. Reading the input size `n`

        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong(); // 2. Reading the array elements
        }

        long[] abs_a = new long[n]; // 3. Creating a copy of the array with absolute values
        for (int i = 0; i < n; i++) {
            abs_a[i] = Math.abs(a[i]);
        }

        long ans = 0; // 4. Calculating the sum of absolute values
        long min = abs_a[0];
        for (long e : abs_a) {
            ans += e;
            if (min > e) {
                min = e;
            }
        }

        int num_negative = 0; // 5. Counting the number of negative elements
        for (long e : a) {
            if (e < 0) {
                num_negative++;
            }
        }

        if (num_negative % 2!= 0) { // 6. Adjusting the sum based on the number of negative elements
            ans -= min * 2;
        }

        System.out.println(ans); // 7. Outputting the result
    }
}
