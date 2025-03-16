import java.awt.geom.Point2D.Double;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.Integer.parseInt;

public class Main {

  // Entry point of the program
  public static void main(String[] args) {
    new Main().run(); // Create an instance of Main and run the program
  }

  public void run() {
    // Use BufferedReader to read input from standard input
    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {

      // Declare points p0, p1, and p2
      Point2D p0, p1, p2;
      // Read the first line of input and split it into coordinates for p0 and p1
      String[] line = br.readLine().split(" ");
      p0 = new Point2D(parseInt(line[0]), parseInt(line[1])); // Initialize point p0
      p1 = new Point2D(parseInt(line[2]), parseInt(line[3])); // Initialize point p1
      int q = parseInt(br.readLine()); // Read the number of queries

      // StringBuilder to accumulate results for output
      StringBuilder buf = new StringBuilder();
      // Process each query
      for(int i=0; i<q; i++) {
        line = br.readLine().split(" "); // Read the coordinates for point p2
        p2 = new Point2D(parseInt(line[0]), parseInt(line[1])); // Initialize point p2
        // Determine the orientation of p2 with respect to the line formed by p0 and p1
        buf.append(jadgeClockwise(p0, p1, p2)).append("\n");
      }

      // Output the accumulated results
      System.out.print(buf);

    } catch(IOException e) {
      // Handle any IO exceptions that may occur during input reading
      System.out.println(e);
    }
  }

  // Method to determine the orientation of point p2 relative to the line formed by p0 and p1
  public String jadgeClockwise(Point2D p0, Point2D p1, Point2D p2) {
    Vector v = new Vector(); // Create a new vector instance
    Point2D a = p1.diff(p0); // Vector from p0 to p1
    Point2D b = p2.diff(p0); // Vector from p0 to p2

    // Determine the orientation using cross product and dot product
    if(v.cross(a, b) > v.EPS) { return "COUNTER_CLOCKWISE"; }
    if(v.cross(a, b) < -v.EPS) { return "CLOCKWISE"; }
    if(v.dot(a, b) < -v.EPS) { return "ONLINE_BACK"; }
    if(a.norm() < b.norm()) { return "ONLINE_FRONT"; }

    return "ON_SEGMENT"; // p2 is on the segment between p0 and p1
  }

  // Inner class representing a 2D point
  private class Point2D extends Double {
    private static final long serialVersionUID = 1L;
    double EPS = 1e-10; // Small epsilon value for floating-point comparisons

    public Point2D() { super(); }
    public Point2D(double x, double y) { super(x, y); }

    // Check if two doubles are approximately equal
    public boolean equals(double a, double b) {
      return Math.abs(a - b) < EPS;
    }

    // Add another point to this point
    public Point2D sum(Point2D b) {
      return new Point2D(x + b.x, y + b.y);
    }

    // Subtract another point from this point
    public Point2D diff(Point2D b) {
      return new Point2D(x - b.x, y - b.y);
    }

    // Multiply this point by a scalar
    public Point2D multiple(double k) {
      return new Point2D(x * k, y * k);
    }

    // Calculate the squared norm of this point
    public double norm() {
      return x * x + y * y;
    }

    // Calculate the absolute distance from this point to another point
    public double abs(Point2D a) {
      return Math.sqrt(a.norm());
    }

    // String representation of the point with formatted coordinates
    @Override
    public String toString() {
      return String.format("%.10f %.10f", x, y);
    }
  }

  // Inner class representing a vector, extending Point2D
  private class Vector extends Point2D {
    private static final long serialVersionUID = 1L;

    public Vector() { super(); }
    public Vector(double x, double y) { super(x, y); }
    public Vector(Point2D p) { super(p.x, p.y); }

    // Calculate the dot product of two points
    public double dot(Point2D a, Point2D b) {
      return a.x * b.x + a.y * b.y;
    }

    // Calculate the cross product of two points
    public double cross(Point2D a, Point2D b) {
      return a.x * b.y - a.y * b.x;
    }

    // Check if two points are orthogonal
    public boolean isOrthogonal(Point2D a, Point2D b) {
      return equals(dot(a, b), 0.0);
    }

    // Check if two line segments are orthogonal
    public boolean isOrthogonal(Point2D a1, Point2D a2, Point2D b1, Point2D b2) {
      return isOrthogonal(a1.diff(a2), b1.diff(b2));
    }

    // Check if two points are parallel
    public boolean isParallel(Point2D a, Point2D b) {
      return equals(cross(a, b), 0.0);
    }

    // Check if two line segments are parallel
    public boolean isParallel(Point2D a1, Point2D a2, Point2D b1, Point2D b2) {
      return isParallel(a1.diff(a2), b1.diff(b2));
    }

    // Project point p onto the line segment defined by sp1 and sp2
    public Point2D project(Point2D sp1, Point2D sp2, Point2D p) {
      Vector base = new Vector(sp2.diff(sp1)); // Direction vector of the line segment
      double r = dot(p.diff(sp1), base) / base.norm(); // Projection scalar

      return sp1.sum(base.multiple(r)); // Return the projected point
    }

    // Reflect point p across the line segment defined by sp1 and sp2
    public Point2D reflect(Point2D sp1, Point2D sp2, Point2D p) {
      return p.sum(project(sp1, sp2, p).diff(p).multiple(2.0)); // Return the reflected point
    }
  }
}
