import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    private ArrayList<Point> points; // Initialize an ArrayList to store points

    public Main() {
        points = new ArrayList<>(); // Constructor initializes the points ArrayList
    }

    // Recursively produces sub-skyline from a list of points
    public ArrayList<Point> produceSubSkyLines(ArrayList<Point> list) {
        int size = list.size();
        if (size == 1) {
            return list; // If the list has one point, return it as the skyline
        } else if (size == 2) {
            if (list.get(0).dominates(list.get(1))) {
                list.remove(1); // Remove the dominated point
            } else if (list.get(1).dominates(list.get(0))) {
                list.remove(0); // Remove the dominating point
            }
            return list; // Return the cleaned list
        }
        ArrayList<Point> leftHalf = new ArrayList<>(list.subList(0, size / 2)); // Split the list into two halves
        ArrayList<Point> rightHalf = new ArrayList<>(list.subList(size / 2, size));
        ArrayList<Point> leftSkyline = produceSubSkyLines(leftHalf); // Recursively find the skyline of the left half
        ArrayList<Point> rightSkyline = produceSubSkyLines(rightHalf); // Recursively find the skyline of the right half
        return produceFinalSkyLine(leftSkyline, rightSkyline); // Merge the two skylines
    }

    // Merges two sub-skyline lists into a final skyline
    public ArrayList<Point> produceFinalSkyLine(ArrayList<Point> left, ArrayList<Point> right) {
        ArrayList<Point> finalSkyline = new ArrayList<>();
        int i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left.get(i).x < right.get(j).x) {
                finalSkyline.add(left.get(i)); // Add the point from the left list
                i++;
            } else if (left.get(i).x > right.get(j).x) {
                finalSkyline.add(right.get(j)); // Add the point from the right list
                j++;
            } else { 
                finalSkyline.add(left.get(i).y < right.get(j).y ? left.get(i) : right.get(j)); // Add the point with the lower y-coordinate
                i++;
                j++;
            }
        }
        while (i < left.size()) {
            finalSkyline.add(left.get(i)); // Add remaining points from the left list
            i++;
        }
        while (j < right.size()) {
            finalSkyline.add(right.get(j)); // Add remaining points from the right list
            j++;
        }
        return finalSkyline; // Return the merged skyline
    }

    // Represents a point with x and y coordinates
    public static class Point {
        private int x;
        private int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y; // Constructor initializes the x and y coordinates
        }

        public int getX() {
            return x; // Returns the x-coordinate
        }

        public int getY() {
            return y; // Returns the y-coordinate
        }

        // Checks if the current point dominates another point
        public boolean dominates(Point p1) {
            return ((this.x < p1.x && this.y <= p1.y) || (this.x <= p1.x && this.y < p1.y));
        }

        @Override
        public String toString() {
            return x + " " + y; // Returns a string representation of the point
        }
    }

    // Main method to read input, find the skyline, and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<Point> points = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points.add(new Point(x, y));
        }
        points.sort(Comparator.comparingInt(Point::getX)); // Sort points by x-coordinate
        Main skyline = new Main();
        ArrayList<Point> result = skyline.produceSubSkyLines(points);
        System.out.println("Final Skyline:");
        for (Point point : result) {
            System.out.println(point); // Print each point in the final skyline
        }
        scanner.close(); // Close the scanner
    }
}
