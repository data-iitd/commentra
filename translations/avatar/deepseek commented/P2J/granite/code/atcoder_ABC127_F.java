
import java.util.Scanner;
import java.util.PriorityQueue;

public class atcoder_ABC127_F{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        long[] ans = new long[2];
        PriorityQueue<Long> p1 = new PriorityQueue<>();
        PriorityQueue<Long> p2 = new PriorityQueue<>((a, b) -> Long.compare(b, a));
        long sumB = 0;
        long sumP1 = 0;
        long sumP2 = 0;

        for (int i = 0; i < q; i++) {
            int type = sc.nextInt();
            if (type == 1) {
                long a = sc.nextLong();
                long b = sc.nextLong();
                sumB += b;
                if (p1.isEmpty()) {
                    p1.add(a);
                    sumP1 += a;
                } else if (p1.peek() <= a) {
                    p1.add(a);
                    sumP1 += a;
                } else {
                    p2.add(-a);
                    sumP2 += a;
                }
                if (p1.size() < p2.size()) {
                    long k = p2.poll();
                    p1.add(-k);
                    sumP2 -= k;
                    sumP1 += k;
                }
                if (p1.size() - 1 > p2.size()) {
                    long k = p1.poll();
                    p2.add(-k);
                    sumP1 -= k;
                    sumP2 += k;
                }
            } else {
                if (p1.size() == p2.size()) {
                    System.out.println(-p2.peek() + " " + (sumP1 - p1.size() * -p2.peek() + p2.size() * -p2.peek() - sumP2 + sumB));
                } else {
                    System.out.println(p1.peek() + " " + (sumP1 - p1.size() * p1.peek() + p2.size() * p1.peek() - sumP2 + sumB));
                }
            }
        }
    }
}

