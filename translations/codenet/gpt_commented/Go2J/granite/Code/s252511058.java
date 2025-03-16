
import java.util.Arrays;
import java.util.Scanner;

public class s252511058{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Point[] points = new Point[N];
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int L = sc.nextInt();
            points[i] = new Point(x, x - L, x + L);
        }
        Arrays.sort(points);
        int start = points[0].r;
        int ans = 1;
        for (int i = 1; i < N; i++) {
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

        public Point(int x, int l, int r) {
            this.x = x;
            this.l = l;
            this.r = r;
        }

        @Override
        public int compareTo(Point o) {
            return this.r - o.r;
        }
    }
}

