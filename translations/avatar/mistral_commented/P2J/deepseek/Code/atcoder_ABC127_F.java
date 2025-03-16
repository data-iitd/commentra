import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        int[] ans = {0, 0};

        PriorityQueue<Integer> p1 = new PriorityQueue<>();
        PriorityQueue<Integer> p2 = new PriorityQueue<>((a, b) -> b - a);

        int sum_b = 0;
        int sum_p1 = 0;
        int sum_p2 = 0;

        for (int i = 0; i < q; i++) {
            int[] ql = new int[3];
            ql[0] = scanner.nextInt();
            ql[1] = scanner.nextInt();
            ql[2] = scanner.nextInt();

            if (ql[0] == 2) {
                if (p1.size() == p2.size()) {
                    System.out.println(-p2.peek() + " " + (sum_p1 - p1.size() * -p2.peek() + p2.size() * -p2.peek() - sum_p2 + sum_b));
                } else {
                    System.out.println(p1.peek() + " " + (sum_p1 - p1.size() * p1.peek() + p2.size() * p1.peek() - sum_p2 + sum_b));
                }
            } else {
                sum_b += ql[2];

                if (p1.isEmpty()) {
                    p1.add(ql[1]);
                    sum_p1 += ql[1];
                } else if (p1.peek() <= ql[1]) {
                    p1.add(ql[1]);
                    sum_p1 += ql[1];
                } else {
                    p2.add(ql[1]);
                    sum_p2 += ql[1];
                    sum_p1 -= ql[1];
                    sum_p2 -= ql[1];
                }

                if (p1.size() < p2.size()) {
                    int k = p2.poll();
                    p1.add(-k);
                    sum_p2 += k;
                    sum_p1 -= k;
                }

                if (p1.size() - 1 > p2.size()) {
                    int k = p1.poll();
                    p2.add(-k);
                    sum_p1 -= k;
                    sum_p2 += k;
                }
            }
        }
    }
}
