
import java.util.*;

class atcoder_ABC127_F {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        long[] ans = new long[2];
        PriorityQueue<Long> p1 = new PriorityQueue<>();
        PriorityQueue<Long> p2 = new PriorityQueue<>(Collections.reverseOrder());
        long sum_b = 0;
        long sum_p1 = 0;
        long sum_p2 = 0;
        for (int i = 0; i < q; i++) {
            int ql = sc.nextInt();
            if (ql == 1) {
                long a = sc.nextLong();
                long b = sc.nextLong();
                sum_b += b;
                if (p1.isEmpty()) {
                    p1.add(a);
                    sum_p1 += a;
                } else if (p1.peek() <= a) {
                    p1.add(a);
                    sum_p1 += a;
                } else {
                    p2.add(a);
                    sum_p2 += a;
                }
                if (p1.size() < p2.size()) {
                    long k = p2.poll();
                    p1.add(k);
                    sum_p2 -= k;
                    sum_p1 += k;
                }
                if (p1.size() - 1 > p2.size()) {
                    long k = p1.poll();
                    p2.add(k);
                    sum_p1 -= k;
                    sum_p2 += k;
                }
            } else {
                if (p1.size() == p2.size()) {
                    System.out.println(-p2.peek() + " " + (sum_p1 - p1.size() * -p2.peek() + p2.size() * -p2.peek() - sum_p2 + sum_b));
                } else {
                    System.out.println(p1.peek() + " " + (sum_p1 - p1.size() * p1.peek() + p2.size() * p1.peek() - sum_p2 + sum_b));
                }
            }
        }
    }
}
