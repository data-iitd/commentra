

import java.util.Scanner;

public class s860368733{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt();
        }
        int a, b;
        int count = 0;
        for (int i = 0; i < m; i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            if (h[a - 1] < h[b - 1]) {
                count++;
            } else if (h[a - 1] > h[b - 1]) {
                count++;
            } else if (h[a - 1] == h[b - 1]) {
                count += 2;
            }
        }
        System.out.println(n - count);
    }
}

