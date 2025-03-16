
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            int d = sc.nextInt();
            int s = sc.nextInt();
            pq.add(-d);
            pq.add(-s);
        }
        int sum = 0;
        while (!pq.isEmpty()) {
            int d = -pq.poll();
            int s = -pq.poll();
            if (m - d >= 0) {
                sum += s;
                m -= d;
            } else {
                pq.add(-s);
            }
        }
        System.out.println(sum);
    }
}

