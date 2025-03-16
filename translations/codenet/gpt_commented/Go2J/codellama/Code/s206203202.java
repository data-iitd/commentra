package main;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        Map<Integer, Boolean> hm = new HashMap<>();
        while (true) {
            if (!hm.containsKey(N)) {
                hm.put(N, true);
                N = Math.abs(N - K);
            } else {
                break;
            }
        }

        int mini = 999999999;
        for (int k : hm.keySet()) {
            mini = Math.min(mini, k);
        }
        System.out.println(mini);
    }
}

