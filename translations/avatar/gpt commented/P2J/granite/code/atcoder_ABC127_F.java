
import java.util.*;

public class atcoder_ABC127_F{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        int[] ans = new int[2];
        PriorityQueue<Integer> p1 = new PriorityQueue<>();
        PriorityQueue<Integer> p2 = new PriorityQueue<>(Collections.reverseOrder());
        int sumB = 0;
        int sumP1 = 0;
        int sumP2 = 0;
        for (int i = 0; i < q; i++) {
            int t = sc.nextInt();
            if (t == 1) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                sumB += b;
                if (p1.isEmpty()) {
                    p1.add(a);
                    sumP1 += a;
                } else if (a <= p1.peek()) {
                    p1.add(a);
                    sumP1 += a;
                } else {
                    p2.add(-a);
                    sumP2 -= a;
                }
                if (p1.size() < p2.size()) {
                    int k = p2.poll();
                    p1.add(-k);
                    sumP2 += k;
                    sumP1 -= k;
                } else if (p1.size() - 1 > p2.size()) {
                    int k = p1.poll();
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
