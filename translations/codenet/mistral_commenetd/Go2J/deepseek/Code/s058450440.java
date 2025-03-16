import java.io.*;
import java.util.*;

public class Main {
    static int ans = 0;
    static List<Integer> a = new ArrayList<>();

    public static void dfs(int left, int i, int res) {
        if (left == 0) {
            ans += res;
            return;
        }

        for (int j = i; j < a.size(); j++) {
            dfs(left - 1, j + 1, res * a.get(j));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());

        Map<Character, Integer> dic = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String s = reader.readLine();
            char c = s.charAt(0);
            if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
                dic.put(c, dic.getOrDefault(c, 0) + 1);
            }
        }

        for (int value : dic.values()) {
            a.add(value);
        }

        dfs(3, 0, 1);
        System.out.println(ans);
    }
}
