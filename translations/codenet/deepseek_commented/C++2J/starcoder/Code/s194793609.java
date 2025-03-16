import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 1. Reading the input size `n`

        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong(); // 2. Reading the array elements
        }

        long[] abs_a = Arrays.copyOf(a, n); // 3. Creating a copy of the array with absolute values

        for (int i = 0; i < n; i++) {
            if (abs_a[i] < 0) {
                abs_a[i] = -abs_a[i];
            }
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

        if (num_negative % 2) { // 6. Adjusting the sum based on the number of negative elements
            ans -= min * 2;
        }

        System.out.println(ans); // 7. Outputting the result
    }
}
