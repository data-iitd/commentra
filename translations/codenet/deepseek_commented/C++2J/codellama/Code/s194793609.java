import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 1. Reading the input size `n`

        Vector<Long> a = new Vector<Long>(n);
        for (int i = 0; i < n; i++) {
            a.add(sc.nextLong()); // 2. Reading the array elements
        }

        Vector<Long> abs_a = new Vector<Long>(a); // 3. Creating a copy of the array with absolute values

        for (int i = 0; i < n; i++) {
            if (abs_a.get(i) < 0) {
                abs_a.set(i, -abs_a.get(i));
            }
        }

        long ans = 0; // 4. Calculating the sum of absolute values
        long min = abs_a.get(0);
        for (int i = 0; i < n; i++) {
            ans += abs_a.get(i);
            if (min > abs_a.get(i)) {
                min = abs_a.get(i);
            }
        }

        int num_negative = 0; // 5. Counting the number of negative elements
        for (int i = 0; i < n; i++) {
            if (a.get(i) < 0) {
                num_negative++;
            }
        }

        if (num_negative % 2) { // 6. Adjusting the sum based on the number of negative elements
            ans -= min * 2;
        }

        System.out.println(ans); // 7. Outputting the result
    }
}

