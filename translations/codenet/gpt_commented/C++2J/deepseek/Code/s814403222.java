import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            if (n == 0) break;

            int m;
            Pair[] v = new Pair[22];
            List<Integer>[] d = new ArrayList[33];

            for (int i = 0; i < 33; i++) {
                d[i] = new ArrayList<>();
            }

            for (int i = 0; i < n; i++) {
                v[i] = new Pair(0, "");
                scanner.nextLine(); // Consume newline
                String[] input = scanner.nextLine().split(" ");
                v[i].second = input[0];
                m = Integer.parseInt(input[1]);

                for (int j = 0; j < m; j++) {
                    int a = scanner.nextInt();
                    v[i].first += n - d[a].size();

                    for (int k = 0; k < d[a].size(); k++) {
                        v[d[a].get(k)].first--;
                    }

                    d[a].add(i);
                }
            }

            Arrays.sort(v, 0, n);
            System.out.println(v[0].first + " " + v[0].second);
        }
        scanner.close();
    }

    static class Pair implements Comparable<Pair> {
        int first;
        String second;

        Pair(int first, String second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair other) {
            return Integer.compare(this.first, other.first);
        }
    }
}
