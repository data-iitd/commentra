import java.util.*;
public final class Main {
    private Main() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of points
        List<Point> points = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points.add(new Point(x, y)); // Add each point to the list
        }
        List<Point> bruteForceHull = convexHullBruteForce(points); // Calculate convex hull using brute force
        System.out.println("Convex Hull (Brute Force):");
        for (Point p : bruteForceHull) {
            System.out.println(p.x + " " + p.y); // Print each point in the convex hull
        }
        List<Point> recursiveHull = convexHullRecursive(points); // Calculate convex hull using recursion
        System.out.println("Convex Hull (Recursive):");
        for (Point p : recursiveHull) {
            System.out.println(p.x + " " + p.y); // Print each point in the convex hull
        }
        scanner.close(); // Close the scanner
    }
    private static boolean checkPointOrientation(Point i, Point j, Point k) {
        int detK = Point.orientation(i, j, k); // Determine the orientation of points i, j, and k
        if (detK > 0) {
            return true; // Points are in counterclockwise order
        } else if (detK < 0) {
            return false; // Points are in clockwise order
        } else {
            return k.compareTo(i) >= 0 && k.compareTo(j) <= 0; // Points are collinear
        }
    }
    public static List<Point> convexHullBruteForce(List<Point> points) {
        Set<Point> convexSet = new TreeSet<>(Comparator.naturalOrder()); // Use a TreeSet to store unique points in sorted order
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
        return new ArrayList<>(convexSet); // Return the convex hull as a list
    }
    public static List<Point> convexHullRecursive(List<Point> points) {
        Collections.sort(points); // Sort the points
        Set<Point> convexSet = new HashSet<>(); // Use a HashSet to store unique points
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
        constructHull(upperHull, leftMostPoint, rightMostPoint, convexSet); // Construct the upper hull
        constructHull(lowerHull, rightMostPoint, leftMostPoint, convexSet); // Construct the lower hull
        List<Point> result = new ArrayList<>(convexSet);
        Collections.sort(result); // Sort the result to ensure correct order
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
                constructHull(candidatePoints, left, extremePoint, convexSet); // Recursively construct the hull on the left side
                convexSet.add(extremePoint); // Add the extreme point to the convex set
                constructHull(candidatePoints, extremePoint, right, convexSet); // Recursively construct the hull on the right side
            }
        }
    }
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
