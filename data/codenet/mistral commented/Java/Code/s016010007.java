
import java.awt.geom.Point2D.Double;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.Integer.parseInt;

public class Main {

  public static void main(String[] args) {
    // Instantiate and run the Main object
    new Main().run();
  }

  public void run() {

    try {
      // Initialize BufferedReader to read input from System.in
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      // Read the first line containing two points p0 and p1
      Point2D p0 = new Point2D(parseInt(br.readLine().split(" ")[0]), parseInt(br.readLine().split(" ")[1]));
      Point2D p1 = new Point2D(parseInt(br.readLine().split(" ")[0]), parseInt(br.readLine().split(" ")[1]));

      // Read the number of queries q
      int q = parseInt(br.readLine());

      // Initialize StringBuilder to store the output
      StringBuilder buf = new StringBuilder();

      // Process each query by reading a point p2 and appending the judgment to the StringBuilder
      for (int i = 0; i < q; i++) {
        String[] line = br.readLine().split(" ");
        Point2D p2 = new Point2D(parseInt(line[0]), parseInt(line[1]));
        String judgment = judgeClockwise(p0, p1, p2);
        buf.append(judgment).append("\n");
      }

      // Print the output to the console
      System.out.print(buf);

      // Close the BufferedReader to release the system resources
      br.close();

    } catch (IOException e) {
      // Print the error message to the console
      System.out.println(e);
    }
  }

  // A method to judge whether three points form a clockwise or counterclockwise direction
  public String judgeClockwise(Point2D p0, Point2D p1, Point2D p2) {
    Vector v = new Vector();
    Point2D a = p1.diff(p0);
    Point2D b = p2.diff(p0);

    // Determine the direction of the vectors a and b based on their cross product
    if (v.cross(a, b) > v.EPS) {
      return "COUNTER_CLOCKWISE";
    } else if (v.cross(a, b) < -v.EPS) {
      return "CLOCKWISE";
    }

    // Determine the relationship between points p0, p1, and p2 based on their position
    if (v.dot(a, b) < -v.EPS) {
      return "ONLINE_BACK";
    } else if (a.norm() < b.norm()) {
      return "ONLINE_FRONT";
    }

    // If the points are on the same line segment, return "ON_SEGMENT"
    return "ON_SEGMENT";
  }

  // A nested class representing a 2D point with some additional methods
  private class Point2D extends Double {
    private static final long serialVersionUID = 1L;
    double EPS = 1e-10;

    // Constructor for a Point2D with default values (0, 0)
    public Point2D() { super(); }

    // Constructor for a Point2D with specified x and y values
    public Point2D(double x, double y) { super(x, y); }

    // Method to check if two points are equal within a certain tolerance
    public boolean equals(double x, double y) {
      return Math.abs(x - this.x) < EPS && Math.abs(y - this.y) < EPS;
    }

    // Method to calculate the difference between two points
    public Point2D diff(Point2D b) {
      return new Point2D(x - b.x, y - b.y);
    }

    // Method to multiply a point by a scalar value
    public Point2D multiple(double k) {
      return new Point2D(x * k, y * k);
    }

    // Method to calculate the Euclidean norm of a point
    public double norm() {
      return x * x + y * y;
    }

    // Method to calculate the absolute value of the difference between two points
    public double abs(Point2D a) {
      return Math.sqrt(a.norm());
    }

    // Override the toString() method to print the point in a more readable format
    @Override
    public String toString() {
      return String.format("%.10f %.10f", x, y);
    }
  }

  // A nested class representing a 2D vector with some additional methods
  private class Vector extends Point2D {

    private static final long serialVersionUID = 1L;

    // Constructor for a Vector with default values (0, 0)
    public Vector() { super(); }

    // Constructor for a Vector with specified x and y values
    public Vector(double x, double y) { super(x, y); }

    // Constructor for a Vector from a Point2D
    public Vector(Point2D p) { super(p.x, p.y); }

    // Method to calculate the dot product of two vectors
    public double dot(Point2D a, Point2D b) {
      return a.x * b.x + a.y * b.y;
    }

    // Method to calculate the cross product of two vectors
    public double cross(Point2D a, Point2D b) {
      return a.x * b.y - a.y * b.x;
    }

    // Method to check if two vectors are orthogonal
    public boolean isOrthogonal(Point2D a, Point2D b) {
      return equals(dot(a, b), 0.0);
    }

    // Method to check if two vectors are parallel
    public boolean isParallel(Point2D a, Point2D b) {
      return equals(cross(a, b), 0.0);
    }

    // Method to project a point onto a line defined by two points
    public Point2D project(Point2D sp1, Point2D sp2, Point2D p) {
      Vector base = new Vector(sp2.diff(sp1));
      double r = dot(p.diff(sp1), base) / base.norm();

      return sp1.sum(base.multiple(r));
    }

    // Method to reflect a point about a line defined by two points
    public Point2D reflect(Point2D sp1, Point2D sp2, Point2D p) {
      return p.sum(project(sp1, sp2, p).diff(p).multiple(2.0));
    }

  }
}