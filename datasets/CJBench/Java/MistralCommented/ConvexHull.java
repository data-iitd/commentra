
import java.util.*;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read input from the console

        int n = scanner.nextInt(); // Read the number of points from the input

        List<Point> points = new ArrayList<>(); // Create an empty ArrayList to store the points

        for (int i = 0; i < n; i++) { // Iterate through the input and add each point to the ArrayList
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points.add(new Point(x, y));
        }

        List<Point> bruteForceHull = convexHullBruteForce(points); // Calculate the convex hull using the brute force method
        System.out.println("Convex Hull (Brute Force):"); // Print the header for the output of the brute force method
        for (Point p : bruteForceHull) { // Iterate through the points in the brute force hull and print their coordinates
            System.out.println(p.x + " " + p.y);
        }

        List<Point> recursiveHull = convexHullRecursive(points); // Calculate the convex hull using the recursive method
        System.out.println("Convex Hull (Recursive):"); // Print the header for the output of the recursive method
        for (Point p : recursiveHull) { // Iterate through the points in the recursive hull and print their coordinates
            System.out.println(p.x + " " + p.y);
        }

        scanner.close(); // Close the Scanner object to release the system resources
    }

    // Convex hull calculation using the brute force method
    private static List<Point> convexHullBruteForce(List<Point> points) {
        Set<Point> convexSet = new TreeSet<>(Comparator.naturalOrder()); // Create an empty TreeSet to store the convex points

        for (int i = 0; i < points.size() - 1; i++) { // Iterate through all pairs of points
            for (int j = i + 1; j < points.size(); j++) {
                boolean allPointsOnOneSide = true; // Assume all points are on the same side initially

                boolean leftSide = checkPointOrientation(points.get(i), points.get(j), points.get((i + 1) % points.size())); // Check the orientation of the points i, j, and (i+1) % points.size()

                for (int k = 0; k < points.size(); k++) { // Check if all points are on the same side
                    if (k != i && k != j && checkPointOrientation(points.get(i), points.get(j), points.get(k)) != leftSide) {
                        allPointsOnOneSide = false; // If a point is not on the same side, break the loop
                        break;
                    }
                }

                if (allPointsOnOneSide) { // If all points are on the same side, add points i and j to the convex set
                    convexSet.add(points.get(i));
                    convexSet.add(points.get(j));
                }
            }
        }

        return new ArrayList<>(convexSet); // Return the convex hull as an ArrayList
    }

    // Convex hull calculation using the recursive method
    public static List<Point> convexHullRecursive(List<Point> points) {
        Collections.sort(points); // Sort the points based on their x-coordinates

        Set<Point> convexSet = new HashSet<>(); // Create an empty HashSet to store the convex points

        Point leftMostPoint = points.get(0); // Set the leftmost point as the first point in the list
        Point rightMostPoint = points.get(points.size() - 1); // Set the rightmost point as the last point in the list

        convexSet.add(leftMostPoint); // Add the leftmost point to the convex set
        convexSet.add(rightMostPoint); // Add the rightmost point to the convex set

        List<Point> upperHull = new ArrayList<>(); // Create an empty ArrayList to store the upper hull points
        List<Point> lowerHull = new ArrayList<>(); // Create an empty ArrayList to store the lower hull points

        for (int i = 1; i < points.size() - 1; i++) { // Iterate through all points except the first and last points
            int det = Point.orientation(leftMostPoint, rightMostPoint, points.get(i)); // Calculate the orientation of points i, leftmost, and rightmost

            if (det > 0) { // If the orientation is positive, add the point to the upper hull
                upperHull.add(points.get(i));
            } else if (det < 0) { // If the orientation is negative, add the point to the lower hull
                lowerHull.add(points.get(i));
            }
        }

        constructHull(upperHull, leftMostPoint, rightMostPoint, convexSet); // Recursively construct the upper hull
        constructHull(lowerHull, rightMostPoint, leftMostPoint, convexSet); // Recursively construct the lower hull

        List<Point> result = new ArrayList<>(convexSet); // Create a copy of the convex set as the result
        Collections.sort(result); // Sort the result based on their x-coordinates

        return result; // Return the convex hull as a sorted ArrayList
    }

    // Recursively construct the convex hull
    private static void constructHull(Collection<Point> points, Point left, Point right, Set<Point> convexSet) {
        if (!points.isEmpty()) { // If there are still points to process
            Point extremePoint = null; // Initialize the extreme point as null
            int extremePointDistance = Integer.MIN_VALUE; // Initialize the extreme point distance as the minimum value

            for (Point p : points) { // Iterate through all points in the collection
                int det = Point.orientation(left, right, p); // Calculate the orientation of points left, right, and p

                if (det > 0) { // If the orientation is positive, check if this point is the extreme point
                    if (det > extremePointDistance) {
                        extremePointDistance = det; // Update the extreme point distance if a new extreme point is found
                        extremePoint = p; // Update the extreme point
                    }
                }
            }

            if (extremePoint != null) { // If an extreme point is found
                constructHull(points, left, extremePoint, convexSet); // Recursively construct the hull with the new extreme point
                convexSet.add(extremePoint); // Add the extreme point to the convex set
                constructHull(points, extremePoint, right, convexSet); // Recursively construct the hull with the new extreme point
            }
        }
    }

    // Point class with x and y coordinates and comparison method
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