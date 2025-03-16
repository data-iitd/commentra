

import java.util.Scanner;

public class atcoder_AGC010_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        if (sum % (n * (n + 1) / 2)!= 0) {
            System.out.println("NO");
        } else {
            int k = sum / (n * (n + 1) / 2);
            int[] b = new int[n];
            for (int i = 0; i < n; i++) {
                b[i] = (k - a[i] + a[(i + 1) % n]) % n;
            }
            boolean flag = true;
            for (int i = 0; i < n; i++) {
                if (b[i]!= 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}

Translate the above Java code to C++ and end with comment "