
package com.company;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        Map<Integer, Integer> as = new HashMap<>();
        for (int i = 1; i <= N; i++) {
            as.put(i, 0);
        }
        for (int i = 0; i < K; i++) {
            int d = sc.nextInt();
            for (int j = 0; j < d; j++) {
                int a = sc.nextInt();
                as.put(a, as.get(a) + 1);
            }
        }
        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : as.entrySet()) {
            if (entry.getValue() == 0) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}

