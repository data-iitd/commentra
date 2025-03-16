
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
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

        List<Integer> a = new ArrayList<>();
        for (int v : dic.values()) {
            a.add(v);
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
        for (int j = i; j < a.size(); j++) {
            dfs(left - 1, j + 1, res * a.get(j));
        }
    }
}

