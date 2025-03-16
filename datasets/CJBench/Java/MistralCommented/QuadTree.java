import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

// Class representing a quadtree node
class Point {
    // x and y coordinates of the point
    public double x;
    public double y;

    // Constructor for Point class
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
}

// Class representing a bounding box
class BoundingBox {
    // Center of the bounding box and its half width
    public Point center;
    public double halfWidth;

    // Constructor for BoundingBox class
    public BoundingBox(Point center, double halfWidth) {
        this.center = center;
        this.halfWidth = halfWidth;
    }

    // Checks if the given point is inside the bounding box
    public boolean containsPoint(Point point) {
        // Check if the given point is within the bounding box
        return point.x >= center.x - halfWidth && point.x <= center.x + halfWidth && point.y >= center.y - halfWidth && point.y <= center.y + halfWidth;
    }

    // Checks if the given bounding box intersects with this bounding box
    public boolean intersectsBoundingBox(BoundingBox otherBoundingBox) {
        // Check if the given bounding box intersects with this bounding box
        return otherBoundingBox.center.x - otherBoundingBox.halfWidth <= center.x + halfWidth && otherBoundingBox.center.x + otherBoundingBox.halfWidth >= center.x - halfWidth && otherBoundingBox.center.y - otherBoundingBox.halfWidth <= center.y + halfWidth
                && otherBoundingBox.center.y + otherBoundingBox.halfWidth >= center.y - halfWidth;
    }
}

// Main class for QuadTree
public class Main {
    // Bounding box and capacity of the current quadtree node
    private final BoundingBox boundary;
    private final int capacity;

    // List to store points and four child nodes of the quadtree
    private List<Point> pointList;
    private Main northWest;
    private Main northEast;
    private Main southWest;
    private Main southEast;

    // Flag to check if the quadtree is divided or not
    private boolean divided;

    // Constructor for Main class
    public Main(BoundingBox boundary, int capacity) {
        this.boundary = boundary;
        this.capacity = capacity;
        this.pointList = new ArrayList<>();
        this.divided = false;
        this.northWest = null;
        this.northEast = null;
        this.southWest = null;
        this.southEast = null;
    }

    // Inserts a point into the quadtree
    public boolean insert(Point point) {
        // Check if the point is null or not inside the bounding box
        if (point == null) {
            return false;
        }
        if (!boundary.containsPoint(point)) {
            return false;
        }

        // If the list is not full, add the point to the list
        if (pointList.size() < capacity) {
            pointList.add(point);
            return true;
        }

        // If the quadtree is not divided, divide it into four quadrants
        if (!divided) {
            subDivide();
        }

        // Recursively insert the point into the appropriate child node
        if (northWest.insert(point)) {
            return true;
        }
        if (northEast.insert(point)) {
            return true;
        }
        if (southWest.insert(point)) {
            return true;
        }
        if (southEast.insert(point)) {
            return true;
        }

        // If the point could not be inserted into any child node, return false
        return false;
    }

    // Divides the quadtree into four quadrants
    private void subDivide() {
        double quadrantHalfWidth = boundary.halfWidth / 2;

        // Initialize the child nodes of the quadtree
        northWest = new Main(new BoundingBox(new Point(boundary.center.x - quadrantHalfWidth, boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), this.capacity);
        northEast = new Main(new BoundingBox(new Point(boundary.center.x + quadrantHalfWidth, boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), this.capacity);
        southWest = new Main(new BoundingBox(new Point(boundary.center.x - quadrantHalfWidth, boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), this.capacity);
        southEast = new Main(new BoundingBox(new Point(boundary.center.x + quadrantHalfWidth, boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), this.capacity);

        // Set the divided flag to true
        divided = true;
    }

    // Queries the quadtree for points within the given bounding box
    public List<Point> query(BoundingBox otherBoundingBox) {
        List<Point> points = new ArrayList<>();

        // If the given bounding box does not intersect with this bounding box, return an empty list
        if (!boundary.intersectsBoundingBox(otherBoundingBox)) {
            return points;
        }

        // Add all the points from the current list that are within the given bounding box
        points.addAll(pointList.stream().filter(otherBoundingBox::containsPoint).collect(Collectors.toList()));

        // Recursively query the child nodes and add their points to the result list
        if (divided) {
            points.addAll(northWest.query(otherBoundingBox));
            points.addAll(northEast.query(otherBoundingBox));
            points.addAll(southWest.query(otherBoundingBox));
            points.addAll(southEast.query(otherBoundingBox));
        }

        // Return the final list of points
        return points;
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the input parameters for the bounding box and capacity
        double centerX = scanner.nextDouble();
        double centerY = scanner.nextDouble();
        double halfWidth = scanner.nextDouble();
        int capacity = scanner.nextInt();

        // Create a new bounding box and quadtree node
        BoundingBox boundary = new BoundingBox(new Point(centerX, centerY), halfWidth);
        Main quadTree = new Main(boundary, capacity);

        // Read the number of points to be inserted and insert them into the quadtree
        int numPoints = scanner.nextInt();
        for (int i = 0; i < numPoints; i++) {
            double x = scanner.nextDouble();
            double y = scanner.nextDouble();
            quadTree.insert(new Point(x, y));
        }

        // Read the query parameters and query the quadtree for points within the given bounding box
        double queryCenterX = scanner.nextDouble();
        double queryCenterY = scanner.nextDouble();
        double queryHalfWidth = scanner.nextDouble();
        BoundingBox queryBox = new BoundingBox(new Point(queryCenterX, queryCenterY), queryHalfWidth);
        List<Point> result = quadTree.query(queryBox);

        // Print the result
        System.out.println("Points in range:");
        for (Point point : result) {
            System.out.println(point.x + " " + point.y);
        }

        // Close the scanner
        scanner.close();
    }
}
