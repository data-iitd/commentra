
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class s058450440{
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            char c = reader.readLine().charAt(0);
            if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
                map.put(c, map.getOrDefault(c, 0) + 1);
            }
        }
        int[] a = new int[map.size()];
        int index = 0;
        for (int count : map.values()) {
            a[index++] = count;
        }
        int ans = 0;
        dfs(3, 0, 1, a);
        System.out.println(ans);
    }

    private static void dfs(int left, int i, int res, int[] a) {
        if (left == 0) {
            ans += res;
            return;
        }
        for (int j = i; j < a.length; j++) {
            dfs(left - 1, j + 1, res * a[j], a);
        }
    }
}

// Translate the above Java code to C++ and end with comment "