import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

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

        for (Point point : points) {
            ArrayList<Double> angles = new ArrayList<>();
            for (Point other : points) {
                if (point.equals(other)) {
                    continue;
                }
                double angle = Math.atan2(other.x - point.x, other.y - point.y);
                angles.add(angle);
            }
            Collections.sort(angles);
            angles.add(angles.get(0) + 2 * Math.PI);

            double maxGap = 0;
            for (int i = 0; i < angles.size() - 1; i++) {
                double a = angles.get(i);
                double b = angles.get(i + 1);
                if (b - a >= Math.PI) {
                    maxGap = Math.max(maxGap, (b - a) - Math.PI);
                }
            }

            System.out.println(maxGap / (2 * Math.PI));
        }
    }

    static class Point {
        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Point point = (Point) o;
            return x == point.x && y == point.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }
}

