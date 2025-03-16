
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
public class SkylineAlgorithm {
    private ArrayList<Point> points;
    public SkylineAlgorithm() {
        points = new ArrayList<>();
    }
    public ArrayList<Point> produceSubSkyLines(ArrayList<Point> list) {
        int size = list.size();
        if (size == 1) {
            return list;
        } else if (size == 2) {
            if (list.get(0).dominates(list.get(1))) {
                list.remove(1);
            } else if (list.get(1).dominates(list.get(0))) {
                list.remove(0);
            }
            return list;
        }
        ArrayList<Point> leftHalf = new ArrayList<>(list.subList(0, size / 2));
        ArrayList<Point> rightHalf = new ArrayList<>(list.subList(size / 2, size));
        ArrayList<Point> leftSkyline = produceSubSkyLines(leftHalf);
        ArrayList<Point> rightSkyline = produceSubSkyLines(rightHalf);
        return produceFinalSkyLine(leftSkyline, rightSkyline);
    }
    public ArrayList<Point> produceFinalSkyLine(ArrayList<Point> left, ArrayList<Point> right) {
        ArrayList<Point> finalSkyline = new ArrayList<>();
        int i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left.get(i).x < right.get(j).x) {
                finalSkyline.add(left.get(i));
                i++;
            } else if (left.get(i).x > right.get(j).x) {
                finalSkyline.add(right.get(j));
                j++;
            } else { 
                finalSkyline.add(left.get(i).y < right.get(j).y ? left.get(i) : right.get(j));
                i++;
                j++;
            }
        }
        while (i < left.size()) {
            finalSkyline.add(left.get(i));
            i++;
        }
        while (j < right.size()) {
            finalSkyline.add(right.get(j));
            j++;
        }
        return finalSkyline;
    }
    public static class Point {
        private int x;
        private int y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public int getX() {
            return x;
        }
        public int getY() {
            return y;
        }
        public boolean dominates(Point p1) {
            return ((this.x < p1.x && this.y <= p1.y) || (this.x <= p1.x && this.y < p1.y));
        }
        @Override
        public String toString() {
            return x + " " + y;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<Point> points = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points.add(new Point(x, y));
        }
        points.sort(Comparator.comparingInt(Point::getX));
        SkylineAlgorithm skyline = new SkylineAlgorithm();
        ArrayList<Point> result = skyline.produceSubSkyLines(points);
        System.out.println("Final Skyline:");
        for (Point point : result) {
            System.out.println(point);
        }
        scanner.close();
    }
}
