import java.io.*;
import java.util.*;

public class Main {
    static int[] a;
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

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        Map<Character, Integer> dic = new HashMap<>();
        a = new int[5];

        for (int i = 0; i < n; i++) {
            char c = reader.readLine().charAt(0);
            if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
                dic.put(c, dic.getOrDefault(c, 0) + 1);
            }
        }

        int index = 0;
        for (int count : dic.values()) {
            a[index++] = count;
        }

        dfs(3, 0, 1);
        System.out.println(ans);
    }
}
