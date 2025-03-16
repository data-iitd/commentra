
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
                case 'M':
                case 'A':
                case 'R':
                case 'C':
                case 'H':
                    dic.put(c, dic.getOrDefault(c, 0) + 1);
                    break;
            }
        }
        int[] a = new int[dic.size()];
        int i = 0;
        for (Map.Entry<Character, Integer> entry : dic.entrySet()) {
            a[i++] = entry.getValue();
        }
        dfs(3, 0, 1);
        System.out.println(ans);
    }

    static int ans = 0;

    static void dfs(int left, int i, int res) {
        if (left == 0) {
            ans += res;
            return;
        }
        for (int j = i; j < a.length; j++) {
            dfs(left - 1, j + 1, res * a[j]);
        }
    }
}

// 