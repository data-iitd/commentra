
import java.util.Arrays;
import java.util.Scanner;

public class s851255999{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Work[] ws = new Work[n];
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int n = scanner.nextInt();
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

    static class Work implements Comparable<Work> {
        int time, limit;

        public Work(int time, int limit) {
            this.time = time;
            this.limit = limit;
        }

        @Override
        public int compareTo(Work o) {
            return Integer.compare(this.limit, o.limit);
        }
    }
}

// Translate the above Java code to C++ and end with comment "