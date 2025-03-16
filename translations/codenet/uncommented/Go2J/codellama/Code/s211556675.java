
package main

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();
        int ma = max(A, B, C);
        int rest = 0;
        if (ma == A) {
            rest += B + C;
        } else if (ma == B) {
            rest += A + C;
        } else {
            rest += A + B;
        }
        for (int i = 1; i <= K; i++) {
            ma *= 2;
        }

        System.out.println(ma + rest);
    }

    public static int max(int... nums) {
        int m = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (m < nums[i]) {
                m = nums[i];
            }
        }
        return m;
    }
}

