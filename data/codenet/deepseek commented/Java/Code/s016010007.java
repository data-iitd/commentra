import java.awt.geom.Point2D.Double;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.Integer.parseInt;

public class Main {

  // Main method is the entry point of the program.
  public static void main(String[] args) {
    new Main().run();
  }

  // The run method handles input and output operations.
  public void run() {

    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {

      // Declare points p0, p1, and p2.
      Point2D p0, p1, p2;
      // Read the first line of input and split it into parts.
      String[] line = br.readLine().split(" ");
      // Initialize p0 with the first two numbers from the input.
      p0 = new Point2D(parseInt(line[0]), parseInt(line[1]));
      // Initialize p1 with the next two numbers from the input.
      p1 = new Point2D(parseInt(line[2]), parseInt(line[3]));
      // Read the number of queries.
      int q = parseInt(br.readLine());

      // StringBuilder to build the output.
      StringBuilder buf = new StringBuilder();
      // Loop through each query.
      for(int i=0; i<q; i++) {
        // Read the next line of input and split it into parts.
        line = br.readLine().split(" ");
        // Initialize p2 with the next two numbers from the input.
        p2 = new Point2D(parseInt(line[0]), parseInt(line[1]));
        // Append the result of jadgeClockwise to the StringBuilder.
        buf.append(jadgeClockwise(p0, p1, p2)).append("\n");
      }

      // Print the results.
      System.out.print(buf);

    }
    catch( IOException e ) {
      // Print any IO exceptions that occur.
      System.out.println(e);
    }
  }

  // Method to determine the relative position of p2 with respect to the line segment formed by p0 and p1.
  public String jadgeClockwise (Point2D p0, Point2D p1, Point2D p2) {
    // Create a Vector object.
    Vector v = new Vector();
    // Calculate vectors a and b.
    Point2D a = p1.diff(p0);
    Point2D b = p2.diff(p0);

    // Determine the relative position using vector operations.
    if(v.cross(a, b) >  v.EPS ) { return "COUNTER_CLOCKWISE"; }
    if(v.cross(a, b) < -v.EPS ) { return "CLOCKWISE"; }
    if(v.dot(a, b) < -v.EPS ) { return "ONLINE_BACK"; }
    if(a.norm() < b.norm()) { return "ONLINE_FRONT"; }

    return "ON_SEGMENT";
  }

  // Point2D class extends Double and represents a 2D point with geometric operations.
  private class Point2D extends Double {
    private static final long serialVersionUID = 1L;
    double EPS = 1e-10;

    // Default constructor.
    public Point2D() { super(); }
    // Constructor with x and y coordinates.
    public Point2D(double x, double y) { super(x, y); }

    // Method to check if two doubles are equal within a small epsilon.
    public boolean equals (double a, double b) {
      return Math.abs(a-b) < EPS;
    }
    // Method to add two points.
    public Point2D sum(Point2D b) {
      return new Point2D(x+b.x, y+b.y);
    }
    // Method to subtract two points.
    public Point2D diff(Point2D b) {
      return new Point2D(x-b.x, y-b.y);
    }
    // Method to multiply a point by a scalar.
    public Point2D multiple(double k) {
      return new Point2D(x*k, y*k);
    }
    // Method to calculate the norm of the point.
    public double norm() {
      return x * x + y * y;
    }
    // Method to calculate the absolute value of a point.
    public double abs(Point2D a) {
      return Math.sqrt(a.norm());
    }

    @Override
    public String toString() {
      return String.format("%.10f %.10f", x,y);
    }
  }

  // Vector class extends Point2D and represents a vector with vector operations.
  private class Vector extends Point2D {

    private static final long serialVersionUID = 1L;

    // Default constructor.
    public Vector() { super(); }
    // Constructor with x and y coordinates.
    public Vector(double x, double y) { super(x, y); }
    // Constructor with a Point2D object.
    public Vector(Point2D p) { super(p.x, p.y); }

    // Method to calculate the dot product of two vectors.
    public double dot(Point2D a, Point2D b) {
      return a.x * b.x + a.y * b.y;
    }
    // Method to calculate the cross product of two vectors.
    public double cross(Point2D a, Point2D b) {
      return a.x * b.y - a.y * b.x;
    }
    // Method to check if two vectors are orthogonal.
    public boolean isOrthogonal(Point2D a, Point2D b) {
      return equals(dot(a,b) , 0.0);
    }
    // Method to check if two line segments are orthogonal.
    public boolean isOrthogonal(Point2D a1, Point2D a2, Point2D b1, Point2D b2) {
      return isOrthogonal(a1.diff(a2), b1.diff(b2));
    }
    // Method to check if two vectors are parallel.
    public boolean isParallel(Point2D a, Point2D b) {
      return equals(cross(a, b), 0.0);
    }
    // Method to check if two line segments are parallel.
    public boolean isParallel(Point2D a1, Point2D a2, Point2D b1, Point2D b2) {
      return isParallel(a1.diff(a2), b1.diff(b2));
    }

    // Method to project a point onto a line segment.
    public Point2D project(Point2D sp1, Point2D sp2, Point2D p) {
      Vector base = new Vector( sp2.diff(sp1) );
      double r = dot(p.diff(sp1), base) / base.norm();

      return sp1.sum(base.multiple(r));
    }
    // Method to reflect a point over a line segment.
    public Point2D reflect(Point2D sp1, Point2D sp2, Point2D p) {
      return p.sum(project(sp1,sp2,p).diff(p).multiple(2.0));
    }

  }
}
