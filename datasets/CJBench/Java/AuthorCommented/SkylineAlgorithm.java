

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

/**
 * @author dimgrichr
 * <p>
 * Space complexity: O(n) Time complexity: O(nlogn), because it is a divide and
 * conquer algorithm
 */
public class SkylineAlgorithm {

    private ArrayList<Point> points;

    /**
     * Main constructor of the application. ArrayList points gets created, which
     * represents the sum of all edges.
     */
    public SkylineAlgorithm() {
        points = new ArrayList<>();
    }

    /**
     * The main divide and conquer, and also recursive algorithm. It gets an
     * ArrayList full of points as an argument. If the size of that ArrayList is
     * 1 or 2, the ArrayList is returned as it is, or with one less point (if
     * the initial size is 2 and one of it's points, is dominated by the other
     * one). On the other hand, if the ArrayList's size is bigger than 2, the
     * function is called again, twice, with arguments the corresponding half of
     * the initial ArrayList each time. Once the flashback has ended, the
     * function produceFinalSkyLine gets called, in order to produce the final
     * skyline, and return it.
     *
     * @param list, the initial list of points
     * @return leftSkyLine, the combination of first half's and second half's
     * skyline
     * @see Point
     */
    public ArrayList<Point> produceSubSkyLines(ArrayList<Point> list) {
        // part where function exits flashback
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

        // recursive part of the function
        ArrayList<Point> leftHalf = new ArrayList<>(list.subList(0, size / 2));
        ArrayList<Point> rightHalf = new ArrayList<>(list.subList(size / 2, size));

        ArrayList<Point> leftSkyline = produceSubSkyLines(leftHalf);
        ArrayList<Point> rightSkyline = produceSubSkyLines(rightHalf);

        // skyline is produced
        return produceFinalSkyLine(leftSkyline, rightSkyline);
    }

    /**
     * The first half's skyline gets cleared from some points that are not part
     * of the final skyline (Points with same x-value and different y=values.
     * The point with the smallest y-value is kept). Then, the minimum y-value
     * of the points of first half's skyline is found. That helps us to clear
     * the second half's skyline, because, the points of second half's skyline
     * that have greater y-value of the minimum y-value that we found before,
     * are dominated, so they are not part of the final skyline. Finally, the
     * "cleaned" first half's and second half's skylines, are combined,
     * producing the final skyline, which is returned.
     *
     * @param left the skyline of the left part of points
     * @param right the skyline of the right part of points
     * @return left the final skyline
     */
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
            } else { // Same x coordinate, choose the smaller y value
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
        /**
         * The main constructor of Point Class, used to represent the 2
         * Dimension points.
         *
         * @param x the point's x-value.
         * @param y the point's y-value.
         */

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        /**
         * @return x, the x-value
         */
        public int getX() {
            return x;
        }

        /**
         * @return y, the y-value
         */
        public int getY() {
            return y;
        }

        /**
         * Based on the skyline theory, it checks if the point that calls the
         * function dominates the argument point.
         *
         * @param p1 the point that is compared
         * @return true if the point wich calls the function dominates p1 false
         * otherwise.
         */
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

        // Input number of points
        int n = scanner.nextInt();
        ArrayList<Point> points = new ArrayList<>();

        // Input points
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points.add(new Point(x, y));
        }

        // Sort points by x-coordinate
        points.sort(Comparator.comparingInt(Point::getX));

        SkylineAlgorithm skyline = new SkylineAlgorithm();
        ArrayList<Point> result = skyline.produceSubSkyLines(points);

        // Output final skyline
        System.out.println("Final Skyline:");
        for (Point point : result) {
            System.out.println(point);
        }

        scanner.close();
    }
}
