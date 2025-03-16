
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println(min(n*a, b));
    }

    public static int min(int... nums) {
        int min = nums[0];
        for (int v : nums) {
            if (v < min) {
                min = v;
            }
        }
        return min;
    }
}

