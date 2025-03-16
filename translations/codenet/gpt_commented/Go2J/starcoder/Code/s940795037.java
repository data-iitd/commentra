package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            double tmp = 1.0 / sc.nextInt();
            ans += tmp;
        }
        System.out.printf("%.10f\n", 1.0 / ans);
    }
}

