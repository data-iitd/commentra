
import java.util.Scanner;

public class atcoder_ABC162_D{
    public static void main(String[] args) {
        // Taking input for N and S
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        String S = scanner.next();

        // Defining the function calculate that takes two parameters, n and s
        int calculate(int n, String s) {
            // Converting the string s into a character array
            char[] arr = s.toCharArray();

            // Calculating the counts of 'R', 'G', and 'B'
            int rNum = 0, gNum = 0, bNum = 0;
            for (char c : arr) {
                if (c == 'R') rNum++;
                else if (c == 'G') gNum++;
                else if (c == 'B') bNum++;
            }

            // Initializing sum to 0
            int sum = 0;

            // Iterating over possible step sizes from 1 to Math.ceil(n / 2) + 1
            for (int step = 1; step <= Math.ceil(n / 2.0); step++) {
                // Iterating over possible starting indices for the substring
                for (int i = 0; i <= n - 2 * step; i++) {
                    // Forming a substring of length 3
                    String s1 = String.valueOf(arr[i]);
                    String s2 = String.valueOf(arr[i + step]);
                    String s3 = String.valueOf(arr[i + step * 2]);
                    String s = s1 + s2 + s3;

                    // Checking if the substring matches any of the patterns
                    if (s.equals("RGB") || s.equals("RBG") || s.equals("BGR") || s.equals("BRG") || s.equals("GBR") || s.equals("GRB")) {
                        sum++;
                    }
                }
            }

            // Printing the product of the counts of 'R', 'G', and 'B' minus sum
            System.out.println(rNum * gNum * bNum - sum);

            return 0;
        }

        // Calling the function calculate with N and S as arguments
        calculate(N, S);
    }
}

Translate the above Java code to C++ and end with comment "