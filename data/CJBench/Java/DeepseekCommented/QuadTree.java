import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

// Represents a point in a 2D space with x and y coordinates.
class Point {
    public double x;
    public double y;
    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
}

// Represents a bounding box with a center point and a half-width.
class BoundingBox {
    public Point center;
    public double halfWidth;
    BoundingBox(Point center, double halfWidth) {
        this.center = center;
        this.halfWidth = halfWidth;
    }

    // Checks if a point is contained within the bounding box.
    public boolean containsPoint(Point point) {
        return point.x >= center.x - halfWidth && point.x <= center.x + halfWidth && point.y >= center.y - halfWidth && point.y <= center.y + halfWidth;
    }

    // Checks if the bounding box intersects with another bounding box.
    public boolean intersectsBoundingBox(BoundingBox otherBoundingBox) {
        return otherBoundingBox.center.x - otherBoundingBox.halfWidth <= center.x + halfWidth && otherBoundingBox.center.x + otherBoundingBox.halfWidth >= center.x - halfWidth && otherBoundingBox.center.y - otherBoundingBox.halfWidth <= center.y + halfWidth
            && otherBoundingBox.center.y + otherBoundingBox.halfWidth >= center.y - halfWidth;
    }
}

// Represents the quadtree data structure.
public class Main {
    private final BoundingBox boundary;
    private final int capacity;
    private List<Point> pointList; // List to store points in the current node.
    private boolean divided; // Flag to check if the quadtree is divided.
    private Main northWest; // Reference to the north-west child quadtree.
    private Main northEast; // Reference to the north-east child quadtree.
    private Main southWest; // Reference to the south-west child quadtree.
    private Main southEast; // Reference to the south-east child quadtree.

    // Constructor to initialize the quadtree with a boundary and capacity.
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

    // Inserts a point into the quadtree.
    public boolean insert(Point point) {
        if (point == null) {
            return false;
        }
        if (!boundary.containsPoint(point)) {
            return false;
        }
        if (pointList.size() < capacity) {
            pointList.add(point);
            return true;
        }
        if (!divided) {
            subDivide();
        }
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
        return false;
    }

    // Subdivides the quadtree into four child quadtrees.
    private void subDivide() {
        double quadrantHalfWidth = boundary.halfWidth / 2;
        northWest = new Main(new BoundingBox(new Point(boundary.center.x - quadrantHalfWidth, boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), this.capacity);
        northEast = new Main(new BoundingBox(new Point(boundary.center.x + quadrantHalfWidth, boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), this.capacity);
        southWest = new Main(new BoundingBox(new Point(boundary.center.x - quadrantHalfWidth, boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), this.capacity);
        southEast = new Main(new BoundingBox(new Point(boundary.center.x + quadrantHalfWidth, boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), this.capacity);
        divided = true;
    }

    // Returns a list of points within a given bounding box.
    public List<Point> query(BoundingBox otherBoundingBox) {
        List<Point> points = new ArrayList<>();
        if (!boundary.intersectsBoundingBox(otherBoundingBox)) {
            return points;
        }
        points.addAll(pointList.stream().filter(otherBoundingBox::containsPoint).collect(Collectors.toList()));
        if (divided) {
            points.addAll(northWest.query(otherBoundingBox));
            points.addAll(northEast.query(otherBoundingBox));
            points.addAll(southWest.query(otherBoundingBox));
            points.addAll(southEast.query(otherBoundingBox));
        }
        return points;
    }

    // Main method to read input, insert points, and query for points within a bounding box.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double centerX = scanner.nextDouble();
        double centerY = scanner.nextDouble();
        double halfWidth = scanner.nextDouble();
        int capacity = scanner.nextInt();
        BoundingBox boundary = new BoundingBox(new Point(centerX, centerY), halfWidth);
        Main quadTree = new Main(boundary, capacity);
        int numPoints = scanner.nextInt();
        for (int i = 0; i < numPoints; i++) {
            double x = scanner.nextDouble();
            double y = scanner.nextDouble();
            quadTree.insert(new Point(x, y));
        }
        double queryCenterX = scanner.nextDouble();
        double queryCenterY = scanner.nextDouble();
        double queryHalfWidth = scanner.nextDouble();
        BoundingBox queryBox = new BoundingBox(new Point(queryCenterX, queryCenterY), queryHalfWidth);
        List<Point> result = quadTree.query(queryBox);
        System.out.println("Points in range:");
        for (Point point : result) {
            System.out.println(point.x + " " + point.y);
        }
        scanner.close();
    }
}
