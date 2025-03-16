import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = Integer.parseInt(scanner.nextLine());
        long[] ans = {0, 0};
        PriorityQueue<Integer> p1 = new PriorityQueue<>();
        PriorityQueue<Integer> p2 = new PriorityQueue<>(Collections.reverseOrder());
        long sum_b = 0;
        long sum_p1 = 0;
        long sum_p2 = 0;

        for (int i = 0; i < q; i++) {
            String[] input = scanner.nextLine().split(" ");
            int type = Integer.parseInt(input[0]);
            if (type == 2) {
                if (p1.size() == p2.size()) {
                    System.out.println(-p2.peek() + sum_p1 - p1.size() * -p2.peek() + p2.size() * -p2.peek() - sum_p2 + sum_b);
                } else {
                    System.out.println(p1.peek() + sum_p1 - p1.size() * p1.peek() + p2.size() * p1.peek() - sum_p2 + sum_b);
                }
            } else {
                int value = Integer.parseInt(input[1]);
                sum_b += Integer.parseInt(input[2]);
                if (p1.isEmpty()) {
                    p1.offer(value);
                    sum_p1 += value;
                } else if (p1.peek() <= value) {
                    p1.offer(value);
                    sum_p1 += value;
                } else {
                    p2.offer(value);
                    sum_p2 += value;
                }
                if (p1.size() < p2.size()) {
                    int k = p2.poll();
                    p1.offer(k);
                    sum_p2 -= k;
                    sum_p1 += k;
                }
                if (p1.size() - 1 > p2.size()) {
                    int k = p1.poll();
                    p2.offer(k);
                    sum_p1 -= k;
                    sum_p2 += k;
                }
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
