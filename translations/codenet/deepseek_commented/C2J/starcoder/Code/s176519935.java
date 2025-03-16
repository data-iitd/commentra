import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = sc.nextLong();
        PriorityQueue<Long> pq = new PriorityQueue<Long>(Collections.reverseOrder());
        for (int i = 0; i < n; i++) pq.add(a[i]);
        for (int i = 0; i < m; i++) {
            long tm = pq.poll();
            tm /= 2;
            pq.add(tm);
        }
        long ans = 0;
        while (!pq.isEmpty()) ans += pq.poll();
        System.out.println(ans);
    }
}
