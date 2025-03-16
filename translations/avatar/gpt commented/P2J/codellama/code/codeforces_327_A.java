import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        if (s.indexOf('0') == -1) {
            System.out.println(n - 1);
        } else {
            int[] indices = new int[s.length()];
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '0') {
                    indices[i] = 1;
                }
            }
            if (indices[0] == 1 && indices[indices.length - 1] == 1) {
                System.out.println(n);
            } else {
                int maximum = 0;
                for (int i = 0; i < indices.length - 1; i++) {
                    if (indices[i] == 1 && indices[i + 1] == 1) {
                        maximum = Math.max(maximum, 2 + 2 * (Math.abs(i - i + 1) - 1) - (Math.abs(i - i - 1) - 1));
                    }
                }
                System.out.println(s.replace("1", "").length() + maximum);
            }
        }
    }
}

