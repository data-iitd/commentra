import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        PriorityQueue<int[]> x = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        PriorityQueue<Integer> y = new PriorityQueue<>();
        
        for (int i = 0; i < n; i++) {
            int day = scanner.nextInt();
            int salary = scanner.nextInt();
            x.add(new int[]{-day, -salary});
        }
        
        while (!x.isEmpty()) {
            int[] ds = x.poll();
            int d = ds[0];
            int s = ds[1];
            int r = m - y.size();
            
            if (r >= -d) {
                y.add(-s);
            } else {
                y.add(-s);
                y.poll();
            }
        }
        
        int sum = 0;
        for (int salary : y) {
            sum += salary;
        }
        
        System.out.println(sum);
    }
}
