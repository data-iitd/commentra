
import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Work[] ws = new Work[n];
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int n = sc.nextInt();
            ws[i] = new Work(a, n);
        }
        Arrays.sort(ws);

        long sum = 0;
        for (Work w : ws) {
            sum += w.time;
            if (sum > w.limit) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}

class Work implements Comparable<Work> {
    int time;
    int limit;

    public Work(int time, int limit) {
        this.time = time;
        this.limit = limit;
    }

    @Override
    public int compareTo(Work o) {
        return this.limit - o.limit;
    }
}

