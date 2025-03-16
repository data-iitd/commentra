import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        PriorityQueue<Long> pq = new PriorityQueue<>((a, b) -> b.compareTo(a));
        for (int i = 0; i < n; i++) {
            long a = scanner.nextLong();
            pq.add(a);
        }
        for (int i = 0; i < m; i++) {
            long tm = pq.poll();
            tm /= 2;
            pq.add(tm);
        }
        long ans = 0;
        for (long num : pq) {
            ans += num;
        }
        System.out.println(ans);
    }
}
