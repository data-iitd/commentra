

import java.util.Scanner;

public class s823623405{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = scanner.nextInt();
        }
        int[] ps = new int[1000001];
        for (int i = 0; i < n; i++) {
            int a = as[i];
            for (int j = 2; j * j <= a; j++) {
                while (a % j == 0) {
                    ps[j]++;
                    a /= j;
                }
            }
            if (a!= 1) {
                ps[a]++;
            }
        }
        int x = 1;
        for (int i = 2; i <= 1000000; i++) {
            for (int j = 0; j < ps[i]; j++) {
                x *= i;
                x %= 1000000007;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += x;
            ans %= 1000000007;
            ans -= as[i];
            ans += 1000000007;
            ans %= 1000000007;
        }
        System.out.println(ans);
    }
}

