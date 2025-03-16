import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        List<List<Integer>> li = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int k = scanner.nextInt();
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < k; j++) {
                row.add(scanner.nextInt());
            }
            li.add(row);
        }
        int[] p = new int[m];
        for (int i = 0; i < m; i++) {
            p[i] = scanner.nextInt();
        }
        scanner.close();

        int ans = 0;
        for (int bit = 0; bit < (1 << n); bit++) {
            Set<Integer> q = new HashSet<>();
            for (int i = 0; i < n; i++) {
                if ((bit & (1 << i)) != 0) {
                    q.add(i + 1);
                }
            }
            boolean valid = true;
            for (int i = 0; i < m; i++) {
                int count = 0;
                for (int bulb : li.get(i)) {
                    if (q.contains(bulb)) {
                        count++;
                    }
                }
                if (count % 2 != p[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
