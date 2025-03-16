import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Point implements Comparable<Point> {
    int x, l, r;

    Point(int x, int l) {
        this.x = x;
        this.l = l;
        this.r = x + l;
    }

    @Override
    public int compareTo(Point other) {
        return Integer.compare(this.r, other.r);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        List<Point> points = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            int x = scanner.nextInt();
            int l = scanner.nextInt();
            points.add(new Point(x, l));
        }

        Collections.sort(points);

        int start = points.get(0).r;
        int ans = 1;

        for (int i = 0; i < points.size(); i++) {
            if (points.get(i).l < start) {
                continue;
            }
            start = points.get(i).r;
            ans++;
        }

        System.out.println(ans);
    }
}

