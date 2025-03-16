
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        Map<Character, Integer> dic = new HashMap<>();

        for (int i = 0; i < n; i++) {
            char c = reader.readLine().charAt(0);
            switch (c) {
                case 'M', 'A', 'R', 'C', 'H':
                    dic.put(c, dic.getOrDefault(c, 0) + 1);
            }
        }

        int[] a = new int[5];
        int ans = 0;

        for (char c : dic.keySet()) {
            a[c - 'A'] = dic.get(c);
        }

        dfs(3, 0, 1);
        System.out.println(ans);
    }

    private static void dfs(int left, int i, int res) {
        if (left == 0) {
            ans += res;
            return;
        }
        for (int j = i; j < a.length; j++) {
            dfs(left - 1, j + 1, res * a[j]);
        }
    }
}

