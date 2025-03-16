

import java.util.Scanner;

public class codeforces_333_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] b = new int[2 * n];
        for (int i = 0; i < 2 * n; i++) {
            b[i] = 1;
        }
        b[0] = b[n - 1] = b[n] = b[2 * n - 1] = 0;
        for (int i = 0; i < m; i++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            b[r - 1] = b[n + c - 1] = 0;
        }
        if (n % 2 == 1 && b[n / 2] == 1 && b[n + n / 2] == 1) {
            b[n / 2] = 0;
        }
        int sum = 0;
        for (int i = 0; i < 2 * n; i++) {
            sum += b[i];
        }
        System.out.println(sum);
    }
}

Translate the above Python code to C++ and end with comment "