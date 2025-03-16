
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        String S = in.next();
        calculate(N, S);
    }

    public static void calculate(int n, String s) {
        char[] arr = s.toCharArray();
        int rNum = 0, gNum = 0, bNum = 0;
        for (char c : arr) {
            if (c == 'R') {
                rNum++;
            } else if (c == 'G') {
                gNum++;
            } else {
                bNum++;
            }
        }
        int sum = 0;
        for (int step = 1; step <= (int) Math.ceil(n / 2.0); step++) {
            for (int i = 0; i <= n - 2 * step; i++) {
                String s = "" + arr[i] + arr[i + step] + arr[i + step * 2];
                if (s.equals("RGB") || s.equals("RBG") || s.equals("BGR") || s.equals("BRG") || s.equals("GBR") || s.equals("GRB")) {
                    sum++;
                }
            }
        }
        System.out.println(rNum * gNum * bNum - sum);
    }
}

