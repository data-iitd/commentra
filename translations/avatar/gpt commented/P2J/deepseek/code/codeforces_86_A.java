import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int l = scanner.nextInt();
        int r = scanner.nextInt();

        // Initialize the current value to r and a counter for the number of digits
        int curr = r;
        int s = 0;

        // Count the number of digits in the current value (r)
        while (curr > 0) {
            s++;
            curr /= 10;
        }

        // Calculate the first power of ten greater than r
        int first = (int) Math.pow(10, s);

        // Calculate the second value as half of the first power of ten
        int second = first / 2;

        // Initialize the answer variable to store the maximum product found
        int ans = -1;

        // Iterate through the possible candidates: l, r, first, and second
        for (int i : new int[]{l, r, first, second}) {
            // Check if the candidate is within the range [l, r]
            if (i >= l && i <= r) {
                curr = i;
                StringBuilder rev = new StringBuilder();

                // Create the reverse number by subtracting each digit from 9
                String currStr = String.valueOf(curr);
                for (char c : currStr.toCharArray()) {
                    rev.append((char) ('9' - c + '0'));
                }

                // Update the answer with the maximum product of the current number and its reverse
                int revNum = Integer.parseInt(rev.toString());
                ans = Math.max(ans, curr * revNum);
            }
        }

        // Print the maximum product found
        System.out.println(ans);
    }
}
