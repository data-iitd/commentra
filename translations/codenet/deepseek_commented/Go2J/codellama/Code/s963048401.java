
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        int[] xs = new int[1];
        xs[0] = as[0];
        for (int j = 1; j < n; j++) {
            int idx = 0;
            for (int i = 0; i < xs.length; i++) {
                if (xs[i] < as[j]) {
                    idx = i;
                }
            }
            if (idx == xs.length) {
                int[] newXs = new int[xs.length + 1];
                for (int i = 0; i < xs.length; i++) {
                    newXs[i] = xs[i];
                }
                newXs[xs.length] = as[j];
                xs = newXs;
            } else {
                xs[idx] = as[j];
            }
        }
        System.out.println(xs.length);
    }
}

