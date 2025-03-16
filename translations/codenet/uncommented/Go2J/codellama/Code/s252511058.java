
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Point[] points = new Point[N];
        for (int i = 0; i < N; i++) {
            points[i] = new Point(sc.nextInt(), sc.nextInt(), sc.nextInt());
        }
        sort(points);
        int start = points[0].r;
        int ans = 1;
        for (int i = 0; i < N; i++) {
            if (points[i].l < start) {
                continue;
            }
            start = points[i].r;
            ans++;
        }
        System.out.println(ans);
    }

    static class Point implements Comparable<Point> {
        int x, l, r;

        Point(int x, int l, int r) {
            this.x = x;
            this.l = l;
            this.r = r;
        }

        @Override
        public int compareTo(Point o) {
            return this.r - o.r;
        }
    }

    static void sort(Point[] points) {
        for (int i = 0; i < points.length; i++) {
            for (int j = i + 1; j < points.length; j++) {
                if (points[i].compareTo(points[j]) > 0) {
                    Point tmp = points[i];
                    points[i] = points[j];
                    points[j] = tmp;
                }
            }
        }
    }
}

