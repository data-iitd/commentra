import java.util.*;

public class Main {
    static List<Integer> a = new ArrayList<>();
    static int ans = 0;

    public static void dfs(int left, int i, int res) {
        if (left == 0) {
            ans += res;
            return;
        }
        for (int j = i; j < a.size(); j++) {
            dfs(left - 1, j + 1, res * a.get(j));
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Map<Character, Integer> dic = new HashMap<>();

        for (int k = 0; k < n; k++) {
            char c = scanner.next().charAt(0);
            if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
                dic.put(c, dic.getOrDefault(c, 0) + 1);
            }
        }

        for (int v : dic.values()) {
            a.add(v);
        }

        dfs(3, 0, 1);
        System.out.println(ans);
    }
}
// <END-OF-CODE>
