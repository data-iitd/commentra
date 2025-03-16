import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Work[] works = new Work[n];

        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int limit = scanner.nextInt();
            works[i] = new Work(a, limit);
        }

        Arrays.sort(works, Comparator.comparingInt(w -> w.limit));

        long sum = 0;
        for (Work w : works) {
            sum += w.time;
            if (sum > w.limit) {
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

    Work(int time, int limit) {
        this.time = time;
        this.limit = limit;
    }
}

// <END-OF-CODE>
