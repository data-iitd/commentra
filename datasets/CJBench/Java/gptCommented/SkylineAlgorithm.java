import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    // List to store points representing the skyline
    private ArrayList<Point> points;

    // Constructor to initialize the points list
    public Main() {
        points = new ArrayList<>();
    }

    // Method to produce sub-skyline from a given list of points
    public ArrayList<Point> produceSubSkyLines(ArrayList<Point> list) {
        int size = list.size();
        
        // Base case: if there's only one point, return it as the skyline
        if (size == 1) {
            return list;
        } 
        // Base case: if there are two points, determine which one dominates the other
        else if (size == 2) {
            if (list.get(0).dominates(list.get(1))) {
                list.remove(1); // Remove dominated point
            } else if (list.get(1).dominates(list.get(0))) {
                list.remove(0); // Remove dominated point
            }
            return list;
        }

        // Split the list into left and right halves
        ArrayList<Point> leftHalf = new ArrayList<>(list.subList(0, size / 2));
        ArrayList<Point> rightHalf = new ArrayList<>(list.subList(size / 2, size));

        // Recursively compute the skyline for both halves
        ArrayList<Point> leftSkyline = produceSubSkyLines(leftHalf);
        ArrayList<Point> rightSkyline = produceSubSkyLines(rightHalf);

        // Merge the two skylines into a final skyline
        return produceFinalSkyLine(leftSkyline, rightSkyline);
    }

    // Method to merge two skylines into a final skyline
    public ArrayList<Point> produceFinalSkyLine(ArrayList<Point> left, ArrayList<Point> right) {
        ArrayList<Point> finalSkyline = new ArrayList<>();
        int i = 0, j = 0;

        // Merge points from left and right skylines based on x-coordinates
        while (i < left.size() && j < right.size()) {
            if (left.get(i).x < right.get(j).x) {
                finalSkyline.add(left.get(i)); // Add point from left if it has a smaller x
                i++;
            } else if (left.get(i).x > right.get(j).x) {
                finalSkyline.add(right.get(j)); // Add point from right if it has a smaller x
                j++;
            } else { 
                // If x-coordinates are equal, add the point with the smaller y-coordinate
                finalSkyline.add(left.get(i).y < right.get(j).y ? left.get(i) : right.get(j));
                i++;
                j++;
            }
        }

        // Add remaining points from the left skyline
        while (i < left.size()) {
            finalSkyline.add(left.get(i));
            i++;
        }

        // Add remaining points from the right skyline
        while (j < right.size()) {
            finalSkyline.add(right.get(j));
            j++;
        }

        return finalSkyline; // Return the merged final skyline
    }

    // Inner class to represent a point in 2D space
    public static class Point {
        private int x; // x-coordinate
        private int y; // y-coordinate

        // Constructor to initialize a point with x and y coordinates
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        // Getter for x-coordinate
        public int getX() {
            return x;
        }

        // Getter for y-coordinate
        public int getY() {
            return y;
        }

        // Method to check if this point dominates another point
        public boolean dominates(Point p1) {
            return ((this.x < p1.x && this.y <= p1.y) || (this.x <= p1.x && this.y < p1.y));
        }

        // Override toString method for easy point representation
        @Override
        public String toString() {
            return x + " " + y;
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of points from input
        int n = scanner.nextInt();
        ArrayList<Point> points = new ArrayList<>();
        
        // Read each point's coordinates and add to the list
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points.add(new Point(x, y));
        }

        // Sort points based on x-coordinate
        points.sort(Comparator.comparingInt(Point::getX));

        // Create an instance of Main to compute the skyline
        Main skyline = new Main();
        
        // Produce the final skyline from the list of points
        ArrayList<Point> result = skyline.produceSubSkyLines(points);
        
        // Print the final skyline points
        System.out.println("Final Skyline:");
        for (Point point : result) {
            System.out.println(point);
        }
        
        // Close the scanner
        scanner.close();
    }
}
