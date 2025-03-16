
import java.util.Scanner;

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
        sc.close();
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ws[i].time;
            if (sum > ws[i].limit) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}

class Work {
    int time;
    int limit;

    public Work(int time, int limit) {
        this.time = time;
        this.limit = limit;
    }
}

