
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
            while (idx < xs.length && xs[idx] < as[j]) {
                idx++;
            }

            if (idx == xs.length) {
                int[] newXs = new int[xs.length + 1];
                System.arraycopy(xs, 0, newXs, 0, xs.length);
                newXs[xs.length] = as[j];
                xs = newXs;
            } else {
                xs[idx] = as[j];
            }
        }

        System.out.println(xs.length);
    }
}

