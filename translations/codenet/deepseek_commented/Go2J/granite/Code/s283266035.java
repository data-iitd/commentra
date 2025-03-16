

import java.util.Scanner;

public class s283266035{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read an input value for `n` from the user
        int ans = 0; // Initialize a variable `ans` to 0 to store the final answer

        // Loop through values of `i` starting from 1
        for (int i = 1; i * i < n; i++) {
            if (n % i == 0 && n % (n / i - 1) == i) { // Check if `i` is a divisor of `n` and if `n/(i-1)` is also a divisor of `n`
                ans += n / i - 1; // Add `n/(i-1) - 1` to `ans` if both conditions are met
            }
        }

        System.out.println(ans); // Print the value of `ans`
    }
}
