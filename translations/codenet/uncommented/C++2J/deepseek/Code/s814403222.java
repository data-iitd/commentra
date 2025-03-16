import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            if (n == 0) break;
            int[] d = new int[33];
            List<Pair> v = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String name = scanner.next();
                int m = scanner.nextInt();
                v.add(new Pair(0, name));
                for (int j = 0; j < m; j++) {
                    int a = scanner.nextInt();
                    v.get(i).first += n - d[a];
                    for (int k = 0; k < d[a]; k++) {
                        v.get(k).first--;
                    }
                    d[a]++;
                }
            }
            v.sort(Comparator.comparingInt(p -> p.first));
            System.out.println(v.get(0).first + " " + v.get(0).second);
        }
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
