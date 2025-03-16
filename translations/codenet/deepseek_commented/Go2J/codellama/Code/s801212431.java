
package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Initializes the scanner with appropriate buffer sizes and word splitting strategy.
        sc.useDelimiter("\\s+");

        // Reads and returns the next word from the input.
        String next() {
            return sc.next();
        }

        // Returns the minimum of two integers.
        int min(int x, int y) {
            if (x > y) {
                return y;
            } else {
                return x;
            }
        }

        // Main function to execute the program logic.
        void main() {
            String S = next();

            // Initialize counters for '0's and '1's
            int l0 = 0, l1 = 0;
            for (int i = 0; i < S.length(); i++) {
                if (S.charAt(i) == '0') {
                    l0++;
                } else {
                    l1++;
                }
            }
            System.out.println(2 * min(l0, l1));
        }
    }
}

