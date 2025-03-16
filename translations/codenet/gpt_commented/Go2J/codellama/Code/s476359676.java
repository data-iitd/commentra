
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;
        int aPrev = 0;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            switch (a) {
                case a > i || a > aPrev + 1:
                    System.out.println(-1);
                    return;
                case a == aPrev + 1:
                    ans++;
                    break;
                default:
                    ans += a;
                    break;
            }
            aPrev = a;
        }
        System.out.println(ans);
    }
}

