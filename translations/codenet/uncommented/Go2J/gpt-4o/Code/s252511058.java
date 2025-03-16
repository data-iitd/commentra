import java.util.*;

public class Main {
    static class Point {
        int x, l, r;

        Point(int x, int l, int r) {
            this.x = x;
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Point[] points = new Point[N];

        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int L = sc.nextInt();
            points[i] = new Point(x, x - L, x + L);
        }

        Arrays.sort(points, Comparator.comparingInt(p -> p.r));

        // 区間スケジューリング問題に帰着する
        int start = points[0].r;
        int ans = 1;

        for (int i = 1; i < points.length; i++) {
            if (points[i].l < start) {
                continue;
            }
            start = points[i].r;
            ans++;
        }

        System.out.println(ans);
    }
}
// <END-OF-CODE>
