import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        ArrayList<Point> points = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            points.add(new Point(x, y));
        }
        for (int i = 0; i < N; i++) {
            Point p = points.get(i);
            ArrayList<Double> angles = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    Point q = points.get(j);
                    double angle = Math.atan2(q.x - p.x, q.y - p.y);
                    angles.add(angle);
                }
            }
            Collections.sort(angles);
            angles.add(angles.get(0) + 2 * Math.PI);
            double ans = 0;
            for (int j = 0; j < angles.size() - 1; j++) {
                double a = angles.get(j);
                double b = angles.get(j + 1);
                if (b - a >= Math.PI) {
                    ans = b - a - Math.PI;
                }
            }
            System.out.println(ans / (2 * Math.PI));
        }
    }
}

class Point {
    int x;
    int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

