
package com.company;

public class Main {

    public static void main(String[] args) {
        // write your code here
        int k, a, b, c, ans = 0;
        System.out.print("Enter a positive integer k: ");
        k = scanner.nextInt();
        for (a = 1; a <= k; a++) {
            for (b = 1; b <= k; b++) {
                for (c = 1; c <= k; c++) {
                    ans += gcd(a, gcd(b, c));
                }
            }
        }
        System.out.println("The sum of GCD of all combinations of three numbers from 1 to k is: " + ans);
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}

