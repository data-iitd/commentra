import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        work[] ws = new work[n];
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int n = sc.nextInt();
            ws[i] = new work(a, n);
        }
        Arrays.sort(ws, new Comparator<work>() {
            public int compare(work a, work b) {
                return a.limit - b.limit;
            }
        });
        long sum = 0;
        for (work w : ws) {
            sum += w.time;
            if (sum > w.limit) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}

class work {
    int time, limit;
    work(int a, int n) {
        time = a;
        limit = n;
    }
}

