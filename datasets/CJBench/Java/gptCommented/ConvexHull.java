import java.util.*;

public final class Main {
    // Private constructor to prevent instantiation of the Main class
    private Main() {
    }

    public static void main(String[] args) {
        // Create a scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of points from the input
        int n = scanner.nextInt();
        
        // Initialize a list to store the points
        List<Point> points = new ArrayList<>();
        
        // Read each point's coordinates and add them to the list
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points.add(new Point(x, y));
        }
        
        // Calculate the convex hull using the brute force method
        List<Point> bruteForceHull = convexHullBruteForce(points);
        System.out.println("Convex Hull (Brute Force):");
        
        // Print the points in the convex hull obtained from brute force
        for (Point p : bruteForceHull) {
            System.out.println(p.x + " " + p.y);
        }
        
        // Calculate the convex hull using the recursive method
        List<Point> recursiveHull = convexHullRecursive(points);
        System.out.println("Convex Hull (Recursive):");
        
        // Print the points in the convex hull obtained from the recursive method
        for (Point p : recursiveHull) {
            System.out.println(p.x + " " + p.y);
        }
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    // Check the orientation of the triplet (i, j, k)
    private static boolean checkPointOrientation(Point i, Point j, Point k) {
        int detK = Point.orientation(i, j, k);
        // Return true if k is on the left side of the line formed by i and j
        if (detK > 0) {
            return true; 
        } 
        // Return false if k is on the right side of the line formed by i and j
        else if (detK < 0) {
            return false; 
        } 
        // If k is collinear, check if it lies between i and j
        else {
            return k.compareTo(i) >= 0 && k.compareTo(j) <= 0;
        }
    }

    // Calculate the convex hull using a brute force approach
    public static List<Point> convexHullBruteForce(List<Point> points) {
        // Use a set to store unique points in the convex hull
        Set<Point> convexSet = new TreeSet<>(Comparator.naturalOrder());
        
        // Iterate through all pairs of points to find the convex hull
        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                boolean allPointsOnOneSide = true;
                // Determine the orientation of the line segment formed by points i and j
                boolean leftSide = checkPointOrientation(points.get(i), points.get(j), points.get((i + 1) % points.size()));
                
                // Check if all other points are on the same side of the line segment
                for (int k = 0; k < points.size(); k++) {
                    if (k != i && k != j && checkPointOrientation(points.get(i), points.get(j), points.get(k)) != leftSide) {
                        allPointsOnOneSide = false;
                        break;
                    }
                }
                
                // If all points are on one side, add the endpoints to the convex set
                if (allPointsOnOneSide) {
                    convexSet.add(points.get(i));
                    convexSet.add(points.get(j));
                }
            }
        }
        // Return the convex hull as a list
        return new ArrayList<>(convexSet);
    }

    // Calculate the convex hull using a recursive approach
    public static List<Point> convexHullRecursive(List<Point> points) {
        // Sort the points to facilitate the construction of the convex hull
        Collections.sort(points);
        
        // Use a set to store unique points in the convex hull
        Set<Point> convexSet = new HashSet<>();
        
        // Identify the leftmost and rightmost points
        Point leftMostPoint = points.get(0);
        Point rightMostPoint = points.get(points.size() - 1);
        
        // Add the leftmost and rightmost points to the convex set
        convexSet.add(leftMostPoint);
        convexSet.add(rightMostPoint);
        
        // Lists to hold points for the upper and lower hulls
        List<Point> upperHull = new ArrayList<>();
        List<Point> lowerHull = new ArrayList<>();
        
        // Classify points into upper and lower hulls based on their orientation
        for (int i = 1; i < points.size() - 1; i++) {
            int det = Point.orientation(leftMostPoint, rightMostPoint, points.get(i));
            if (det > 0) {
                upperHull.add(points.get(i));
            } else if (det < 0) {
                lowerHull.add(points.get(i));
            }
        }
        
        // Construct the upper and lower hulls recursively
        constructHull(upperHull, leftMostPoint, rightMostPoint, convexSet);
        constructHull(lowerHull, rightMostPoint, leftMostPoint, convexSet);
        
        // Prepare the result by converting the convex set to a list and sorting it
        List<Point> result = new ArrayList<>(convexSet);
        Collections.sort(result);
        return result;
    }

    // Recursively construct the convex hull from a set of candidate points
    private static void constructHull(Collection<Point> points, Point left, Point right, Set<Point> convexSet) {
        if (!points.isEmpty()) {
            Point extremePoint = null;
            int extremePointDistance = Integer.MIN_VALUE;
            List<Point> candidatePoints = new ArrayList<>();
            
            // Find the point that is farthest from the line segment formed by left and right
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
            // If an extreme point is found, recursively construct the hull
            if (extremePoint != null) {
                constructHull(candidatePoints, left, extremePoint, convexSet);
                convexSet.add(extremePoint);
                constructHull(candidatePoints, extremePoint, right, convexSet);
            }
        }
    }

    // Point class representing a point in 2D space
    static class Point implements Comparable<Point> {
        final int x; // x-coordinate
        final int y; // y-coordinate
        
        // Constructor to initialize a point with x and y coordinates
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        // Calculate the orientation of the triplet (i, j, k)
        static int orientation(Point i, Point j, Point k) {
            return (j.y - i.y) * (k.x - j.x) - (j.x - i.x) * (k.y - j.y);
        }
        
        // Compare points for sorting based on x and y coordinates
        @Override
        public int compareTo(Point other) {
            return (this.x == other.x) ? Integer.compare(this.y, other.y) : Integer.compare(this.x, other.x);
        }
    }
}
