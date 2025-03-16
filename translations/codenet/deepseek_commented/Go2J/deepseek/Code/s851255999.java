import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Work implements Comparable<Work> {
    int time;
    int limit;

    Work(int time, int limit) {
        this.time = time;
        this.limit = limit;
    }

    @Override
    public int compareTo(Work other) {
        return Integer.compare(this.limit, other.limit);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        List<Work> works = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int time = scanner.nextInt();
            int limit = scanner.nextInt();
            works.add(new Work(time, limit));
        }

        Collections.sort(works);

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
