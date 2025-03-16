import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    // Array to store buildings and a counter for the number of buildings
    private Building[] buildings;
    private int count;

    // Constructor to initialize the buildings array and count
    public Main(int numBuildings) {
        buildings = new Building[numBuildings];
        count = 0;
    }

    // Method to add a new building with its left, height, and right coordinates
    public void add(int left, int height, int right) {
        buildings[count++] = new Building(left, height, right);
    }

    // Method to find the skyline between two indices using divide and conquer
    public ArrayList<Skyline> findSkyline(int start, int end) {
        // Base case: if there's only one building, return its skyline points
        if (start == end) {
            ArrayList<Skyline> list = new ArrayList<>();
            list.add(new Skyline(buildings[start].left, buildings[start].height));
            list.add(new Skyline(buildings[start].right, 0));
            return list;
        }
        
        // Recursive case: split the buildings into two halves
        int mid = (start + end) / 2;
        ArrayList<Skyline> leftSkyline = findSkyline(start, mid);
        ArrayList<Skyline> rightSkyline = findSkyline(mid + 1, end);
        
        // Merge the two skylines and return the result
        return mergeSkyline(leftSkyline, rightSkyline);
    }

    // Method to merge two skylines into one
    public ArrayList<Skyline> mergeSkyline(ArrayList<Skyline> sky1, ArrayList<Skyline> sky2) {
        ArrayList<Skyline> mergedSkyline = new ArrayList<>();
        int h1 = 0, h2 = 0, maxHeight = 0;

        // Merge the two skylines by comparing their x-coordinates
        while (!sky1.isEmpty() && !sky2.isEmpty()) {
            if (sky1.get(0).x < sky2.get(0).x) {
                int x = sky1.get(0).x;
                h1 = sky1.get(0).height;
                sky1.remove(0);
                maxHeight = Math.max(h1, h2);
                addSkylinePoint(mergedSkyline, x, maxHeight);
            } else {
                int x = sky2.get(0).x;
                h2 = sky2.get(0).height;
                sky2.remove(0);
                maxHeight = Math.max(h1, h2);
                addSkylinePoint(mergedSkyline, x, maxHeight);
            }
        }
        
        // Add any remaining points from the first skyline
        while (!sky1.isEmpty()) {
            mergedSkyline.add(sky1.remove(0));
        }
        
        // Add any remaining points from the second skyline
        while (!sky2.isEmpty()) {
            mergedSkyline.add(sky2.remove(0));
        }
        
        return mergedSkyline;
    }

    // Helper method to add a skyline point if it is not a duplicate height
    private void addSkylinePoint(ArrayList<Skyline> skyline, int x, int height) {
        if (skyline.isEmpty() || skyline.get(skyline.size() - 1).height != height) {
            skyline.add(new Skyline(x, height));
        }
    }

    // Class representing a point in the skyline with x-coordinate and height
    public static class Skyline {
        public int x;
        public int height;

        // Constructor for Skyline
        public Skyline(int x, int height) {
            this.x = x;
            this.height = height;
        }

        // Override toString for easy printing of skyline points
        @Override
        public String toString() {
            return x + " " + height;
        }
    }

    // Class representing a building with left, height, and right coordinates
    public static class Building {
        public int left;
        public int height;
        public int right;

        // Constructor for Building
        public Building(int left, int height, int right) {
            this.left = left;
            this.height = height;
            this.right = right;
        }
    }

    // Main method to execute the skyline problem
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of buildings from input
        int numBuildings = scanner.nextInt();
        Main skylineProblem = new Main(numBuildings);
        
        // Read each building's left, height, and right coordinates
        for (int i = 0; i < numBuildings; i++) {
            int left = scanner.nextInt();
            int height = scanner.nextInt();
            int right = scanner.nextInt();
            skylineProblem.add(left, height, right);
        }
        
        // Find the skyline and print the result
        ArrayList<Skyline> result = skylineProblem.findSkyline(0, numBuildings - 1);
        for (Skyline point : result) {
            System.out.println(point);
        }
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
