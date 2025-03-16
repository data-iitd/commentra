
import java.util.Scanner;

// Final class to avoid extending
public final class Main {
    int numberPoints; // Number of points in the array
    Location[] array; // Array to store the points
    Location point1 = null; // First point of the closest pair
    Location point2 = null; // Second point of the closest pair

    // Private static variables to be accessed by the static methods
    private static double minNum = Double.MAX_VALUE;
    private static int secondCount = 0;

    // Constructor to initialize the number of points and the array size
    public Main(int points) {
        numberPoints = points;
        array = new Location[numberPoints];
    }

    // Inner class to store the x and y coordinates of a point
    public static class Location {
        double x; // X-coordinate of the point
        double y; // Y-coordinate of the point

        // Constructor to initialize the x and y coordinates
        Location(final double xpar, final double ypar) {
            this.x = xpar;
            this.y = ypar;
        }
    }

    // Method to build a Location object with given x and y coordinates
    public Location buildLocation(double x, double y) {
        return new Location(x, y);
    }

    // Method to partition the array using the last element as pivot
    private int xPartition(final Location[] a, final int first, final int last) {
        Location pivot = a[last]; // Set pivot as the last element
        int i = first - 1; // Index of the last element in the left subarray

        for (int j = first; j <= last - 1; j++) {
            // Swap elements if the current element's x-coordinate is smaller than the pivot's x-coordinate
            if (a[j].x <= pivot.x) {
                i++;
                Location temp = a[i]; // Swap the elements
                a[i] = a[j];
                a[j] = temp;
            }
        }
        i++; // Increment i to point to the correct position for the pivot

        Location temp = a[i]; // Swap the pivot and the element at index i
        a[i] = a[last];
        a[last] = temp;

        return i; // Return the index of the pivot's new position
    }

    // Method to perform quicksort on the array using the x-coordinate as the partition key
    public void xQuickSort(final Location[] a, final int first, final int last) {
        if (first < last) { // If the array has more than one element
            int q = xPartition(a, first, last); // Partition the array
            xQuickSort(a, first, q - 1); // Recursively sort the left subarray
            xQuickSort(a, q + 1, last); // Recursively sort the right subarray
        }
    }

    // Method to find the closest pair using brute force when the array size is less than or equal to 3
    public double bruteForce(final Location[] arrayParam) {
        double minValue = Double.MAX_VALUE; // Initialize minimum distance with a large value
        double length; // Distance between two points

        // Iterate through the array and find the minimum distance
        for (int i = 0; i < arrayParam.length - 1; i++) {
            for (int j = i + 1; j < arrayParam.length; j++) {
                double xGap = arrayParam[i].x - arrayParam[j].x; // Difference between x-coordinates
                double yGap = arrayParam[i].y - arrayParam[j].y; // Difference between y-coordinates
                length = Math.sqrt(xGap * xGap + yGap * yGap); // Calculate the distance

                if (length < minValue) { // Update minimum distance if a smaller distance is found
                    minValue = length;
                    if (length < minNum) { // Update the closest pair if the new minimum distance is the smallest found
                        point1 = arrayParam[i];
                        point2 = arrayParam[j];
                    }
                }
            }
        }
        return minValue; // Return the minimum distance
    }

    // Method to find the closest pair using the divide-and-conquer approach
    public double closestPair(final Location[] a, final int indexNum) {
        if (indexNum <= 3) { // If the array size is less than or equal to 3, use brute force
            return bruteForce(a);
        }

        // Divide the array into two halves
        Location[] divideArray = new Location[indexNum];
        System.arraycopy(a, 0, divideArray, 0, indexNum); // Copy the array to a new array for division

        int divideX = indexNum / 2; // Calculate the middle index
        Location[] leftArray = new Location[divideX]; // Initialize left subarray
        Location[] rightArray = new Location[indexNum - divideX]; // Initialize right subarray

        // Copy the left and right halves to their respective arrays
        System.arraycopy(divideArray, 0, leftArray, 0, divideX);
        System.arraycopy(divideArray, divideX, rightArray, 0, indexNum - divideX);

        // Recursively find the minimum distances in the left and right subarrays
        double minLeftArea = closestPair(leftArray, divideX);
        double minRightArea = closestPair(rightArray, indexNum - divideX);

        // Find the minimum distance between points in the first window (the points within the epsilon distance from the middle point)
        double minValue = Math.min(minLeftArea, minRightArea);
        for (int i = 0; i < indexNum; i++) {
            double xGap = Math.abs(divideArray[divideX].x - divideArray[i].x); // Difference between x-coordinates
            if (xGap < minValue) { // Update minimum distance if a smaller distance is found
                secondCount++; // Increment the secondCount variable
            }
        }

        // Find the minimum distance between points in the first window
        Location[] firstWindow = new Location[secondCount]; // Initialize an array to store the points in the first window
        int k = 0; // Initialize an index to store the points in the firstWindow array
        for (int i = 0; i < indexNum; i++) {
            double xGap = Math.abs(divideArray[divideX].x - divideArray[i].x); // Difference between x-coordinates
            if (xGap < minValue) { // Update the firstWindow array with the points in the first window
                firstWindow[k] = divideArray[i];
                k++;
            }
        }

        // Find the minimum distance between any two points in the first window
        for (int i = 0; i < secondCount - 1; i++) {
            for (int j = i + 1; j < secondCount; j++) {
                double xGap = Math.abs(firstWindow[i].x - firstWindow[j].x); // Difference between x-coordinates
                double yGap = Math.abs(firstWindow[i].y - firstWindow[j].y); // Difference between y-coordinates
                length = Math.sqrt(xGap * xGap + yGap * yGap); // Calculate the distance

                if (length < minValue) { // Update minimum distance if a smaller distance is found
                    minValue = length;
                    if (length < minNum) { // Update the closest pair if the new minimum distance is the smallest found
                        point1 = firstWindow[i];
                        point2 = firstWindow[j];
                    }
                }
            }
        }

        // Reset the secondCount variable
        secondCount = 0;

        return minValue; // Return the minimum distance
    }

    // Main method to read input and call the closestPair method
    public static void main(final String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read input

        int n = scanner.nextInt(); // Read the number of points from the input
        Main cp = new Main(n); // Create a Main object with the given number of points

        // Read the points and store them in the array
        for (int i = 0; i < n; i++) {
            double x = scanner.nextDouble();
            double y = scanner.nextDouble();
            cp.array[i] = cp.buildLocation(x, y); // Build a Location object for each point and store it in the array
        }

        // Sort the points using quicksort
        cp.xQuickSort(cp.array, 0, cp.array.length - 1);

        // Find the closest pair and print the result
        double result = cp.closestPair(cp.array, cp.array.length);
        System.out.println("(" + cp.point1.x + ", " + cp.point1.y + ")");
        System.out.println("(" + cp.point2.x + ", " + cp.point2.y + ")");
        System.out.println("Minimum Distance : " + result);

        scanner.close(); // Close the Scanner object
    }
}