import java.util.*;

public class Main {
    static class Pair {
        int first;
        String second;

        Pair(int first, String second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Pair[] v = new Pair[22];
        List<Integer>[] d = new ArrayList[33];

        for (int i = 0; i < 33; i++) {
            d[i] = new ArrayList<>();
        }

        while (true) {
            int n = scanner.nextInt();
            if (n == 0) break;

            for (int i = 0; i < n; i++) {
                v[i] = new Pair(0, "");
                int m = scanner.nextInt();
                v[i].second = scanner.next();
                for (int j = 0; j < m; j++) {
                    int a = scanner.nextInt();
                    v[i].first += n - d[a].size();
                    for (int k = 0; k < d[a].size(); k++) {
                        v[d[a].get(k)].first--;
                    }
                    d[a].add(i);
                }
            }

            Arrays.sort(v, 0, n, Comparator.comparingInt(p -> p.first));
            System.out.println(v[0].first + " " + v[0].second);
        }

        scanner.close();
    }
}
// <END-OF-CODE>
