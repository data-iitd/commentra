import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            if (n == 0) break;
            int[][] d = new int[33][];
            for (int i = 0; i < 33; i++) {
                d[i] = new int[0];
            }
            Pair[] v = new Pair[n];
            for (int i = 0; i < n; i++) {
                v[i] = new Pair(0, "");
            }
            for (int i = 0; i < n; i++) {
                int m = scanner.nextInt();
                v[i].second = scanner.next();
                for (int j = 0; j < m; j++) {
                    int a = scanner.nextInt();
                    v[i].first += n - d[a].length;
                    for (int k = 0; k < d[a].length; k++) {
                        v[d[a][k]].first--;
                    }
                    int[] newD = new int[d[a].length + 1];
                    System.arraycopy(d[a], 0, newD, 0, d[a].length);
                    newD[d[a].length] = i;
                    d[a] = newD;
                }
            }
            Arrays.sort(v, (a, b) -> Integer.compare(a.first, b.first));
            System.out.println(v[0].first + " " + v[0].second);
        }
        scanner.close();
    }

    static class Pair {
        int first;
        String second;

        Pair(int first, String second) {
            this.first = first;
            this.second = second;
        }
    }
}
