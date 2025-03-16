
import java.util.*;

public class s058450440{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            char c = scanner.next().charAt(0);
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
        List<Integer> list = new ArrayList<>(map.values());
        int[] a = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            a[i] = list.get(i);
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

Translate the above Java code to C++ and end with comment "