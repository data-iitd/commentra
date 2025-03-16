

import java.util.*;

class atcoder_ABC125_C {
    static int gcd(int a, int b) {
        // Recursively calculates the greatest common divisor (GCD) of a and b
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static int[] ruiseki_lr(int[] array) {
        // Defines a lambda function to compute GCD
        IntBinaryOperator op = (a, b) -> gcd(a, b);
        // Length of the input array
        int n = array.length;
        // Initialize prefix and suffix GCD arrays
        int[] left = new int[n + 1];
        int[] right = new int[n + 1];
        // Compute prefix GCD array
        for (int i = 0; i < n; i++) {
            left[i + 1] = op.applyAsInt(left[i], array[i]);
        }
        // Compute suffix GCD array
        for (int i = n - 1; i >= 0; i--) {
            right[i] = op.applyAsInt(right[i + 1], array[i]);
        }
        return left;
    }

    public static void main(String[] args) {
        // Read the number of elements
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        // Read the list of elements
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(sc.next());
        }
        // Compute prefix and suffix GCD arrays
        int[] left = ruiseki_lr(a);
        // Initialize the answer variable
        int ans = 0;
        // Iterate through the array to find the maximum GCD
        for (int i = 0; i < n; i++) {
            ans = Math.max(gcd(left[i], right[i + 1]), ans);
        }
        // Print the result
        System.out.println(ans);
    }
}

Translate the above Java code to C++ and end with comment "