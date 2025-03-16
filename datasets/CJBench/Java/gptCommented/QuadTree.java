import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

// Class representing a point in 2D space
class Point {
    public double x; // X coordinate of the point
    public double y; // Y coordinate of the point

    // Constructor to initialize a point with given coordinates
    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
}

// Class representing a bounding box defined by a center point and half width
class BoundingBox {
    public Point center; // Center point of the bounding box
    public double halfWidth; // Half the width (and height) of the bounding box

    // Constructor to initialize a bounding box with a center point and half width
    BoundingBox(Point center, double halfWidth) {
        this.center = center;
        this.halfWidth = halfWidth;
    }

    // Method to check if a point is contained within the bounding box
    public boolean containsPoint(Point point) {
        return point.x >= center.x - halfWidth && point.x <= center.x + halfWidth &&
               point.y >= center.y - halfWidth && point.y <= center.y + halfWidth;
    }

    // Method to check if this bounding box intersects with another bounding box
    public boolean intersectsBoundingBox(BoundingBox otherBoundingBox) {
        return otherBoundingBox.center.x - otherBoundingBox.halfWidth <= center.x + halfWidth &&
               otherBoundingBox.center.x + otherBoundingBox.halfWidth >= center.x - halfWidth &&
               otherBoundingBox.center.y - otherBoundingBox.halfWidth <= center.y + halfWidth &&
               otherBoundingBox.center.y + otherBoundingBox.halfWidth >= center.y - halfWidth;
    }
}

// Main class representing a quadtree structure
public class Main {
    private final BoundingBox boundary; // The bounding box for this node
    private final int capacity; // Maximum number of points allowed in this node before subdivision
    private List<Point> pointList; // List of points contained in this node
    private boolean divided; // Flag indicating whether this node has been subdivided
    private Main northWest; // Northwest child node
    private Main northEast; // Northeast child node
    private Main southWest; // Southwest child node
    private Main southEast; // Southeast child node

    // Constructor to initialize the quadtree node with a bounding box and capacity
    public Main(BoundingBox boundary, int capacity) {
        this.boundary = boundary;
        this.capacity = capacity;
        this.pointList = new ArrayList<>();
        this.divided = false; // Initially, the node is not divided
        this.northWest = null;
        this.northEast = null;
        this.southWest = null;
        this.southEast = null;
    }

    // Method to insert a point into the quadtree
    public boolean insert(Point point) {
        if (point == null) {
            return false; // Return false if the point is null
        }
        if (!boundary.containsPoint(point)) {
            return false; // Return false if the point is outside the bounding box
        }
        if (pointList.size() < capacity) {
            pointList.add(point); // Add the point if there is capacity
            return true;
        }
        if (!divided) {
            subDivide(); // Subdivide the node if it is not already divided
        }
        // Attempt to insert the point into one of the child nodes
        if (northWest.insert(point) || northEast.insert(point) || southWest.insert(point) || southEast.insert(point)) {
            return true;
        }
        return false; // Return false if the point could not be inserted
    }

    // Method to subdivide the current node into four child nodes
    private void subDivide() {
        double quadrantHalfWidth = boundary.halfWidth / 2; // Calculate half width for the quadrants
        // Create child nodes for each quadrant
        northWest = new Main(new BoundingBox(new Point(boundary.center.x - quadrantHalfWidth, boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), this.capacity);
        northEast = new Main(new BoundingBox(new Point(boundary.center.x + quadrantHalfWidth, boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), this.capacity);
        southWest = new Main(new BoundingBox(new Point(boundary.center.x - quadrantHalfWidth, boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), this.capacity);
        southEast = new Main(new BoundingBox(new Point(boundary.center.x + quadrantHalfWidth, boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), this.capacity);
        divided = true; // Mark this node as divided
    }

    // Method to query points within a given bounding box
    public List<Point> query(BoundingBox otherBoundingBox) {
        List<Point> points = new ArrayList<>();
        if (!boundary.intersectsBoundingBox(otherBoundingBox)) {
            return points; // Return empty list if there is no intersection
        }
        // Add points contained in this node's bounding box to the result
        points.addAll(pointList.stream().filter(otherBoundingBox::containsPoint).collect(Collectors.toList()));
        // If this node is divided, query the child nodes
        if (divided) {
            points.addAll(northWest.query(otherBoundingBox));
            points.addAll(northEast.query(otherBoundingBox));
            points.addAll(southWest.query(otherBoundingBox));
            points.addAll(southEast.query(otherBoundingBox));
        }
        return points; // Return the list of points found in the query
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the center coordinates and half width for the bounding box
        double centerX = scanner.nextDouble();
        double centerY = scanner.nextDouble();
        double halfWidth = scanner.nextDouble();
        int capacity = scanner.nextInt(); // Read the capacity for the quadtree

        // Create the bounding box and the quadtree
        BoundingBox boundary = new BoundingBox(new Point(centerX, centerY), halfWidth);
        Main quadTree = new Main(boundary, capacity);

        // Read the number of points to insert into the quadtree
        int numPoints = scanner.nextInt();
        for (int i = 0; i < numPoints; i++) {
            double x = scanner.nextDouble();
            double y = scanner.nextDouble();
            quadTree.insert(new Point(x, y)); // Insert each point into the quadtree
        }

        // Read the query bounding box parameters
        double queryCenterX = scanner.nextDouble();
        double queryCenterY = scanner.nextDouble();
        double queryHalfWidth = scanner.nextDouble();
        BoundingBox queryBox = new BoundingBox(new Point(queryCenterX, queryCenterY), queryHalfWidth);

        // Query the quadtree for points within the specified bounding box
        List<Point> result = quadTree.query(queryBox);
        System.out.println("Points in range:");
        for (Point point : result) {
            System.out.println(point.x + " " + point.y); // Print the points found in the query
        }
        scanner.close(); // Close the scanner
    }
}
