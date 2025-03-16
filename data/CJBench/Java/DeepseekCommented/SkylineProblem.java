import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
public class Main {
    private Building[] buildings; // Array to store the buildings
    private int count; // Counter to keep track of the number of buildings added

    // Constructor to initialize the Main class with a given number of buildings
    public Main(int numBuildings) {
        buildings = new Building[numBuildings]; // Initialize the buildings array
        count = 0; // Initialize the count to 0
    }

    // Method to add a building to the buildings array
    public void add(int left, int height, int right) {
        buildings[count++] = new Building(left, height, right); // Add the building and increment the count
    }

    // Method to find the skyline by recursively dividing the problem into smaller subproblems
    public ArrayList<Skyline> findSkyline(int start, int end) {
        if (start == end) { // Base case: if there's only one building
            ArrayList<Skyline> list = new ArrayList<>();
            list.add(new Skyline(buildings[start].left, buildings[start].height)); // Add the start point of the building
            list.add(new Skyline(buildings[start].right, 0)); // Add the end point of the building
            return list;
        }
        int mid = (start + end) / 2; // Calculate the middle index
        ArrayList<Skyline> leftSkyline = findSkyline(start, mid); // Recursively find the skyline for the left half
        ArrayList<Skyline> rightSkyline = findSkyline(mid + 1, end); // Recursively find the skyline for the right half
        return mergeSkyline(leftSkyline, rightSkyline); // Merge the results of the left and right skylines
    }

    // Method to merge two skylines into one
    public ArrayList<Skyline> mergeSkyline(ArrayList<Skyline> sky1, ArrayList<Skyline> sky2) {
        ArrayList<Skyline> mergedSkyline = new ArrayList<>(); // List to store the merged skyline
        int h1 = 0, h2 = 0, maxHeight = 0; // Initialize heights and maxHeight
        while (!sky1.isEmpty() && !sky2.isEmpty()) { // While both lists are not empty
            if (sky1.get(0).x < sky2.get(0).x) { // If the first point of sky1 is smaller
                int x = sky1.get(0).x;
                h1 = sky1.get(0).height;
                sky1.remove(0);
                maxHeight = Math.max(h1, h2);
                addSkylinePoint(mergedSkyline, x, maxHeight); // Add the point to the merged skyline
            } else { // If the first point of sky2 is smaller
                int x = sky2.get(0).x;
                h2 = sky2.get(0).height;
                sky2.remove(0);
                maxHeight = Math.max(h1, h2);
                addSkylinePoint(mergedSkyline, x, maxHeight); // Add the point to the merged skyline
            }
        }
        while (!sky1.isEmpty()) { // Add remaining points from sky1
            mergedSkyline.add(sky1.remove(0));
        }
        while (!sky2.isEmpty()) { // Add remaining points from sky2
            mergedSkyline.add(sky2.remove(0));
        }
        return mergedSkyline;
    }

    // Private method to add a skyline point if it's not redundant
    private void addSkylinePoint(ArrayList<Skyline> skyline, int x, int height) {
        if (skyline.isEmpty() || skyline.get(skyline.size() - 1).height != height) { // Check for redundancy
            skyline.add(new Skyline(x, height)); // Add the new point
        }
    }

    // Class to represent a skyline point
    public static class Skyline {
        public int x;
        public int height;
        public Skyline(int x, int height) {
            this.x = x;
            this.height = height;
        }
        @Override
        public String toString() {
            return x + " " + height;
        }
    }

    // Class to represent a building
    public static class Building {
        public int left;
        public int height;
        public int right;
        public Building(int left, int height, int right) {
            this.left = left;
            this.height = height;
            this.right = right;
        }
    }

    // Main method to read input, calculate the skyline, and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numBuildings = scanner.nextInt();
        Main skylineProblem = new Main(numBuildings);
        for (int i = 0; i < numBuildings; i++) {
            int left = scanner.nextInt();
            int height = scanner.nextInt();
            int right = scanner.nextInt();
            skylineProblem.add(left, height, right);
        }
        ArrayList<Skyline> result = skylineProblem.findSkyline(0, numBuildings - 1);
        for (Skyline point : result) {
            System.out.println(point);
        }
        scanner.close();
    }
}
