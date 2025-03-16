

import java.util.Scanner;

public class atcoder_ABC114_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Take an integer input N

        // Define a function named `aaa` that takes an argument `n`
        int aaa(int n) {
            // Check if the integer value of `n` is greater than N. If it is, return 0
            if (n > N) {
                return 0;
            }

            // Check if the digits of `n` are '7', '5', and '3'. If they are, set `ans` to 1; otherwise, set `ans` to 0
            int ans = 1;
            if (n % 10!= 7 || (n / 10) % 10!= 5 || (n / 100) % 10!= 3) {
                ans = 0;
            }

            // Iterate over the string '753' and recursively call the function `aaa` with `n` incremented by each digit
            for (char i : "753".toCharArray()) {
                ans += aaa(n + i - '0');
            }

            // Return the value of `ans`
            return ans;
        }

        // Call the function `aaa` with the initial argument '0' and print the result
        System.out.println(aaa(0));
    }
}

