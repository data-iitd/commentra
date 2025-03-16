
// ACM-ICPCアジア地区予選2014 B. Miscalculation

import java.util.Scanner;

public class s611392782{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String s = scanner.next();
            int d = scanner.nextInt();
            int idx = 0;
            int a = add(s, idx);
            idx = 0;
            int b = bob(s, idx);
            if (a == d) {
                System.out.println(b == d? "U" : "M");
            } else {
                System.out.println(b == d? "L" : "I");
            }
        }
    }

    // Function to perform multiplication based on the custom operator '*' in the string
    private static int mul(String str, int[] idx) {
        int res = str.charAt(idx[0]) - '0';
        while (idx[0] + 1 < str.length() && str.charAt(idx[0] + 1) == '*') {
            idx[0] += 2;
            res *= str.charAt(idx[0]) - '0';
        }
        return res;
    }

    // Function to perform addition based on the custom operator '+' in the string
    private static int add(String str, int[] idx) {
        int res = mul(str, idx);
        while (idx[0] + 1 < str.length() && str.charAt(idx[0] + 1) == '+') {
            idx[0] += 2;
            res += mul(str, idx);
        }
        return res;
    }

    // Function to calculate the result based on Bob's interpretation of the expression
    private static int bob(String str, int[] idx) {
        int res = str.charAt(idx[0]) - '0';
        while (idx[0] + 1 < str.length()) {
            if (str.charAt(idx[0] + 1) == '+') {
                res += str.charAt(idx[0] + 2) - '0';
            } else {
                res *= str.charAt(idx[0] + 2) - '0';
            }
            idx[0] += 2;
        }
        return res;
    }
}

