

import java.util.Scanner;

public class atcoder_AGC006_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read the integer input `n`
        String s = scanner.next();  // Read the string `s` of length `n`
        String t = scanner.next();  // Read the string `t` of length `n`

        // Check if the strings `s` and `t` are equal
        if (s.equals(t)) {
            System.out.println(n);  // If they are equal, print `n`
        } else {
            int cnt = 0;  // Initialize the counter `cnt` to 0
            // Compare characters of `s` and `t` starting from each index `i` of `s`
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - i; j++) {
                    // If a mismatch is found, break out of the inner loop
                    if (s.charAt(i + j)!= t.charAt(j)) {
                        break;
                    }
                    // If the end of the inner string is reached without breaking, set `cnt`
                    if (j == n - i - 1) {
                        cnt = n - i;
                    }
                }
            }
            // Print `2 * n - cnt`
            System.out.println(2 * n - cnt);
        }
    }
}
