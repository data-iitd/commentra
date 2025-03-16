
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    // Initialize an empty array of Building objects with a given capacity
    private Building[] buildings;
    private int count;

    public Main(int numBuildings) {
        buildings = new Building[numBuildings];
        count = 0;
    }

    // Add a new Building object to the array and increment the count
    public void add(int left, int height, int right) {
        buildings[count++] = new Building(left, height, right);
    }

    // Find the skyline between two indices using recursion
    public ArrayList<Skyline> findSkyline(int start, int end) {
        if (start == end) { // Base case: if the range is empty, return an empty list with one point
            ArrayList<Skyline> list = new ArrayList<>();
            list.add(new Skyline(buildings[start].left, buildings[start].height));
            list.add(new Skyline(buildings[start].right, 0));
            return list;
        }

        int mid = (start + end) / 2; // Calculate the middle index
        ArrayList<Skyline> leftSkyline = findSkyline(start, mid); // Recursively find the skyline of the left half
        ArrayList<Skyline> rightSkyline = findSkyline(mid + 1, end); // Recursively find the skyline of the right half

        // Merge the two skyline lists into one
        return mergeSkyline(leftSkyline, rightSkyline);
    }

    // Merge two skyline lists into one by comparing their first points
    public ArrayList<Skyline> mergeSkyline(ArrayList<Skyline> sky1, ArrayList<Skyline> sky2) {
        ArrayList<Skyline> mergedSkyline = new ArrayList<>();
        int h1 = 0, h2 = 0, maxHeight = 0; // Initialize variables for heights and maximum height

        // Merge the points until both lists are empty
        while (!sky1.isEmpty() && !sky2.isEmpty()) {
            if (sky1.get(0).x < sky2.get(0).x) { // If the first point of sky1 is left of the first point of sky2
                int x = sky1.get(0).x;
                h1 = sky1.get(0).height;
                sky1.remove(0);
                maxHeight = Math.max(h1, h2);
                addSkylinePoint(mergedSkyline, x, maxHeight);
            } else { // Otherwise, the first point of sky2 is left of the first point of sky1
                int x = sky2.get(0).x;
                h2 = sky2.get(0).height;
                sky2.remove(0);
                maxHeight = Math.max(h1, h2);
                addSkylinePoint(mergedSkyline, x, maxHeight);
            }
        }

        // Add any remaining points from the lists
        while (!sky1.isEmpty()) {
            mergedSkyline.add(sky1.remove(0));
        }
        while (!sky2.isEmpty()) {
            mergedSkyline.add(sky2.remove(0));
        }

        return mergedSkyline;
    }

    // Add a new point to the merged skyline list
    private void addSkylinePoint(ArrayList<Skyline> skyline, int x, int height) {
        if (skyline.isEmpty() || skyline.get(skyline.size() - 1).height != height) { // If the list is empty or the last point has a different height
            skyline.add(new Skyline(x, height));
        }
    }

    // Define a class for a single skyline point
    public static class Skyline {
        public int x;
        public int height;

        public Skyline(int x, int height) {
            this.x = x;
            this.height = height;
        }

        // Override the toString method to print the point in a readable format
        @Override
        public String toString() {
            return x + " " + height;
        }
    }

    // Define a class for a building
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

    // Main method to read input and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read input

        int numBuildings = scanner.nextInt(); // Read the number of buildings
        Main skylineProblem = new Main(numBuildings); // Create a new Main object with the given capacity

        for (int i = 0; i < numBuildings; i++) { // Read the buildings and add them to the Main object
            int left = scanner.nextInt();
            int height = scanner.nextInt();
            int right = scanner.nextInt();
            skylineProblem.add(left, height, right);
        }

        ArrayList<Skyline> result = skylineProblem.findSkyline(0, numBuildings - 1); // Find the skyline of the entire range
        for (Skyline point : result) { // Print each point in the skyline
            System.out.println(point);
        }

        scanner.close(); // Close the Scanner object
    }
}