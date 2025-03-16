
import java.util.*;

class s176519935 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            pq.add(a[i]);
        }
        for (int i = 0; i < m; i++) {
            long tmp = pq.poll();
            pq.add(tmp / 2);
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += pq.poll();
        }
        System.out.println(ans);
    }
}

