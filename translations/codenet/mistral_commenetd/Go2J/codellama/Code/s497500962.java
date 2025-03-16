
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables R, G, B, and N with next integers
        int R = nextInt();
        int G = nextInt();
        int B = nextInt();
        int N = nextInt();

        // Initialize variable ans with zero
        int ans = 0;

        // Nested for loops to iterate through all possible combinations of x and y within the range of N
        for (int x = 0; x <= N; x++) {
            for (int y = 0; y <= N; y++) {
                // Calculate temporary variable tmp
                int tmp = N - R*x - G*y;

                // Check if tmp is non-negative and the remainder of tmp when divided by B is zero
                if (tmp >= 0 && tmp%B == 0) {
                    // Increment the value of ans if the condition is true
                    ans++;
                }
            }
        }

        // Print the value of ans
        System.out.println(ans);
    }

    // Input related functions
    private static Scanner sc = new Scanner(System.in);

    public static int nextInt() {
        // Read next word as string, convert it to integer, and return
        sc.next();
        return Integer.parseInt(sc.next());
    }

    public static float nextFloat() {
        // Read next word as string, convert it to float64, and return
        sc.next();
        return Float.parseFloat(sc.next());
    }

    public static String nextString() {
        // Read next word as string and return
        sc.next();
        return sc.next();
    }

    // Utility functions
    public static int abs(int x) {
        // Return absolute value of x
        return Math.abs(x);
    }

    public static int min(int x, int y) {
        // Return minimum value of x and y
        return Math.min(x, y);
    }

    public static int max(int x, int y) {
        // Return maximum value of x and y
        return Math.max(x, y);
    }
}

