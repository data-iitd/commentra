import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        // Taking the range as input from the user

        int curr = r;
        int s = 0;
        // Initialize curr to r and s to 0

        while (curr > 0) {
            s += 1;
            curr /= 10;
        }
        // Determine the number of digits in r and store it in s

        int first = (int) Math.pow(10, s);
        int second = first / 2;
        // Calculate the smallest number with s digits and its half

        int ans = -1;
        // Initialize ans to -1 to store the maximum product found

        int[] numbers = {l, r, first, second};
        for (int i : numbers) {
            if (i >= l && i <= r) {
                curr = i;
                StringBuilder rev = new StringBuilder();
                String currStr = String.valueOf(curr);
                for (char c : currStr.toCharArray()) {
                    rev.append((char) ('9' - (c - '0') + '0'));
                }
                int product = Integer.parseInt(rev.toString()) * curr;
                ans = Math.max(ans, product);
            }
        }
        // Iterate over the specified numbers, check if they are within the range,
        // reverse the digits, calculate the product, and update ans if necessary

        System.out.println(ans);
        // Print the maximum product found
    }
}
