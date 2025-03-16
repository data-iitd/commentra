
import java.util.*;

/**
 * A class providing algorithms to compute the convex hull of a set of points
 * using brute-force and recursive methods.
 *
 * Convex hull: The smallest convex polygon that contains all the given points.
 *
 * Algorithms provided:
 * 1. Brute-Force Method
 * 2. Recursive (Divide-and-Conquer) Method
 *
 * @author Hardvan
 */
public final class ConvexHull {
    private ConvexHull() {
    }

    /**
     * Main method to take input and display the convex hull using the brute-force and recursive methods.
     *
     * @param args Command-line arguments.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the number of points
        int n = scanner.nextInt();

        // Input the points
        List<Point> points = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points.add(new Point(x, y));
        }

        // Calculate convex hull using brute-force method
        List<Point> bruteForceHull = convexHullBruteForce(points);
        System.out.println("Convex Hull (Brute Force):");
        for (Point p : bruteForceHull) {
            System.out.println(p.x + " " + p.y);
        }

        // Calculate convex hull using recursive method
        List<Point> recursiveHull = convexHullRecursive(points);
        System.out.println("Convex Hull (Recursive):");
        for (Point p : recursiveHull) {
            System.out.println(p.x + " " + p.y);
        }

        scanner.close();
    }

    private static boolean checkPointOrientation(Point i, Point j, Point k) {
        int detK = Point.orientation(i, j, k);
        if (detK > 0) {
            return true; // pointsLeftOfIJ
        } else if (detK < 0) {
            return false; // pointsRightOfIJ
        } else {
            return k.compareTo(i) >= 0 && k.compareTo(j) <= 0;
        }
    }

    public static List<Point> convexHullBruteForce(List<Point> points) {
        Set<Point> convexSet = new TreeSet<>(Comparator.naturalOrder());

        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                boolean allPointsOnOneSide = true;
                boolean leftSide = checkPointOrientation(points.get(i), points.get(j), points.get((i + 1) % points.size()));

                for (int k = 0; k < points.size(); k++) {
                    if (k != i && k != j && checkPointOrientation(points.get(i), points.get(j), points.get(k)) != leftSide) {
                        allPointsOnOneSide = false;
                        break;
                    }
                }

                if (allPointsOnOneSide) {
                    convexSet.add(points.get(i));
                    convexSet.add(points.get(j));
                }
            }
        }

        return new ArrayList<>(convexSet);
    }

    public static List<Point> convexHullRecursive(List<Point> points) {
        Collections.sort(points);
        Set<Point> convexSet = new HashSet<>();
        Point leftMostPoint = points.get(0);
        Point rightMostPoint = points.get(points.size() - 1);

        convexSet.add(leftMostPoint);
        convexSet.add(rightMostPoint);

        List<Point> upperHull = new ArrayList<>();
        List<Point> lowerHull = new ArrayList<>();

        for (int i = 1; i < points.size() - 1; i++) {
            int det = Point.orientation(leftMostPoint, rightMostPoint, points.get(i));
            if (det > 0) {
                upperHull.add(points.get(i));
            } else if (det < 0) {
                lowerHull.add(points.get(i));
            }
        }

        constructHull(upperHull, leftMostPoint, rightMostPoint, convexSet);
        constructHull(lowerHull, rightMostPoint, leftMostPoint, convexSet);

        List<Point> result = new ArrayList<>(convexSet);
        Collections.sort(result);
        return result;
    }

    private static void constructHull(Collection<Point> points, Point left, Point right, Set<Point> convexSet) {
        if (!points.isEmpty()) {
            Point extremePoint = null;
            int extremePointDistance = Integer.MIN_VALUE;
            List<Point> candidatePoints = new ArrayList<>();

            for (Point p : points) {
                int det = Point.orientation(left, right, p);
                if (det > 0) {
                    candidatePoints.add(p);
                    if (det > extremePointDistance) {
                        extremePointDistance = det;
                        extremePoint = p;
                    }
                }
            }

            if (extremePoint != null) {
                constructHull(candidatePoints, left, extremePoint, convexSet);
                convexSet.add(extremePoint);
                constructHull(candidatePoints, extremePoint, right, convexSet);
            }
        }
    }

    /**
     * Class representing a 2D point.
     */
    static class Point implements Comparable<Point> {
        final int x;
        final int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        static int orientation(Point i, Point j, Point k) {
            return (j.y - i.y) * (k.x - j.x) - (j.x - i.x) * (k.y - j.y);
        }

        @Override
        public int compareTo(Point other) {
            return (this.x == other.x) ? Integer.compare(this.y, other.y) : Integer.compare(this.x, other.x);
        }
    }
}
