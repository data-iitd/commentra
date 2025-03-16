
import java.util.Scanner;
import java.util.PriorityQueue;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        PriorityQueue<Integer> x = new PriorityQueue<Integer>();
        PriorityQueue<Integer> y = new PriorityQueue<Integer>();
        for (int i = 0; i < n; i++) {
            int day = sc.nextInt();
            int salary = sc.nextInt();
            x.add(-day);
            x.add(-salary);
        }
        while (x.size() > 0) {
            int d = -x.poll();
            int s = -x.poll();
            int r = m - y.size();
            if (r >= d) {
                y.add(-s);
            } else {
                y.add(-s);
                y.poll();
            }
        }
        int sum = 0;
        for (int i = 0; i < y.size(); i++) {
            sum += y.poll();
        }
        System.out.println(sum);
    }
}

