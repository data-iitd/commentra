import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        PriorityQueue<int[]> x = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(b[0], a[0]); // Max-heap for days
            }
            return Integer.compare(b[1], a[1]); // Max-heap for salary
        });
        PriorityQueue<Integer> y = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            int day = scanner.nextInt();
            int salary = scanner.nextInt();
            x.offer(new int[]{day, salary});
        }

        while (!x.isEmpty()) {
            int[] current = x.poll();
            int d = current[0];
            int s = current[1];
            int r = m - y.size();

            if (r >= d) {
                y.offer(s);
            } else {
                y.offer(s);
                if (y.size() > m) {
                    y.poll();
                }
            }
        }

        int sum = 0;
        while (!y.isEmpty()) {
            sum += y.poll();
        }
        System.out.println(sum);
    }
}
// <END-OF-CODE>
