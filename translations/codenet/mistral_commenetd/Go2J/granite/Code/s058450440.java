
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class s058450440{
    private static int ans = 0;
    private static int[] a;

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            char c = br.readLine().charAt(0);
            switch (c) {
                case 'M':
                case 'A':
                case 'R':
                case 'C':
                case 'H':
                    map.put(c, map.getOrDefault(c, 0) + 1);
                    break;
            }
        }
        a = map.values().stream().mapToInt(Integer::intValue).toArray();
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

// 

