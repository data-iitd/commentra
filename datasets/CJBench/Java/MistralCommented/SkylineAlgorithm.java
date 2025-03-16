
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    // Initialize an empty ArrayList to store points
    private ArrayList<Point> points;
    
    public Main() {
        points = new ArrayList<>();
    }
    
    // Method to produce sub sky lines for left and right halves of the given list
    public ArrayList<Point> produceSubSkyLines(ArrayList<Point> list) {
        int size = list.size();
        
        // Base case: if the list has only one element, return it
        if (size == 1) {
            return list;
        }
        
        // Base case: if the list has only two elements, check dominance and return the non-dominated point
        else if (size == 2) {
            if (list.get(0).dominates(list.get(1))) {
                list.remove(1); // remove the dominated point
            } else if (list.get(1).dominates(list.get(0))) {
                list.remove(0); // remove the dominating point
            }
            return list;
        }
        
        // Recursive case: divide the list into left and right halves and call produceSubSkyLines recursively
        ArrayList<Point> leftHalf = new ArrayList<>(list.subList(0, size / 2));
        ArrayList<Point> rightHalf = new ArrayList<>(list.subList(size / 2, size));
        ArrayList<Point> leftSkyline = produceSubSkyLines(leftHalf); // produce sub skyline for left half
        ArrayList<Point> rightSkyline = produceSubSkyLines(rightHalf); // produce sub skyline for right half
        return produceFinalSkyLine(leftSkyline, rightSkyline); // merge left and right sub sky lines to get the final skyline
    }
    
    // Method to merge two sub sky lines into the final skyline
    public ArrayList<Point> produceFinalSkyLine(ArrayList<Point> left, ArrayList<Point> right) {
        ArrayList<Point> finalSkyline = new ArrayList<>();
        
        int i = 0, j = 0; // initialize pointers for left and right sub sky lines
        
        // Merge the smaller x-coordinate sub skyline into the final skyline
        while (i < left.size() && j < right.size()) {
            if (left.get(i).x < right.get(j).x) {
                finalSkyline.add(left.get(i)); // add point from left sub skyline
                i++;
            } else if (left.get(i).x > right.get(j).x) {
                finalSkyline.add(right.get(j)); // add point from right sub skyline
                j++;
            } else { // if x-coordinates are equal, compare y-coordinates and add the dominating point
                finalSkyline.add(left.get(i).y < right.get(j).y ? left.get(i) : right.get(j));
                i++;
                j++;
            }
        }
        
        // Add remaining points from left and right sub sky lines to the final skyline
        while (i < left.size()) {
            finalSkyline.add(left.get(i));
            i++;
        }
        while (j < right.size()) {
            finalSkyline.add(right.get(j));
            j++;
        }
        
        return finalSkyline;
    }
    
    // Define a Point class with x and y coordinates and dominates method
    public static class Point {
        private int x;
        private int y;
        
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        public int getX() {
            return x;
        }
        
        public int getY() {
            return y;
        }
        
        // Check if this point dominates another point
        public boolean dominates(Point p1) {
            return ((this.x < p1.x && this.y <= p1.y) || (this.x <= p1.x && this.y < p1.y));
        }
        
        @Override
        public String toString() {
            return x + " " + y;
        }
    }
    
    // Main method to read input and call produceSubSkyLines method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // initialize scanner to read input
        
        int n = scanner.nextInt(); // read number of points from input
        ArrayList<Point> points = new ArrayList<>(); // initialize empty ArrayList to store points
        
        for (int i = 0; i < n; i++) { // read x and y coordinates of each point and add it to the ArrayList
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points.add(new Point(x, y));
        }
        
        points.sort(Comparator.comparingInt(Point::getX)); // sort points based on their x-coordinates
        
        Main skyline = new Main(); // create an instance of Main class
        ArrayList<Point> result = skyline.produceSubSkyLines(points); // call produceSubSkyLines method to get the final skyline
        
        System.out.println("Final Skyline:"); // print the header for final skyline
        
        for (Point point : result) { // print each point in the final skyline
            System.out.println(point);
        }
        
        scanner.close(); // close the scanner after reading input
    }
}