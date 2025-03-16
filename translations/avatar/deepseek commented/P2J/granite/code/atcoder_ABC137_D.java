

import java.util.*;

public class atcoder_ABC137_D{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        PriorityQueue<int[]> x = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        PriorityQueue<Integer> y = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            int day = sc.nextInt();
            int salary = sc.nextInt();
            x.offer(new int[]{day, salary});
        }
        while (!x.isEmpty()) {
            int[] job = x.poll();
            int daysLeft = m - y.size();
            if (daysLeft >= job[0]) {
                y.offer(-job[1]);
            } else {
                y.offer(-job[1]);
                y.poll();
            }
        }
        System.out.println(-y.stream().mapToInt(i -> i).sum());
    }
}

Translate the above Java code to C++ and end with comment "