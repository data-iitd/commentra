import java.util.Scanner;

public final class Main {
    // Number of points to be processed
    int numberPoints;
    // Array to hold the locations of the points
    Location[] array;
    // Variables to store the closest pair of points
    Location point1 = null;
    Location point2 = null;
    // Minimum distance initialized to maximum possible value
    private static double minNum = Double.MAX_VALUE;

    // Setter for minimum distance
    public static void setMinNum(double minNum) {
        Main.minNum = minNum;
    }

    // Setter for second count
    public static void setSecondCount(int secondCount) {
        Main.secondCount = secondCount;
    }

    // Counter for the number of points in the second window
    private static int secondCount = 0;

    // Constructor to initialize the number of points and the array
    Main(int points) {
        numberPoints = points;
        array = new Location[numberPoints];
    }

    // Inner class to represent a location with x and y coordinates
    public static class Location {
        double x;
        double y;

        // Constructor to initialize the coordinates
        Location(final double xpar, final double ypar) {
            this.x = xpar;
            this.y = ypar;
        }
    }

    // Method to create a new Location object
    public Location buildLocation(double x, double y) {
        return new Location(x, y);
    }

    // Partitioning method for quicksort based on x-coordinate
    public int xPartition(final Location[] a, final int first, final int last) {
        Location pivot = a[last]; // Choosing the last element as pivot
        int i = first - 1; // Index of smaller element
        Location temp;

        // Rearranging the array based on the pivot
        for (int j = first; j <= last - 1; j++) {
            if (a[j].x <= pivot.x) {
                i++;
                // Swap elements
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        // Swap the pivot element to its correct position
        i++;
        temp = a[i];
        a[i] = a[last];
        a[last] = temp;
        return i; // Return the partitioning index
    }

    // Quicksort method for sorting the locations based on x-coordinate
    public void xQuickSort(final Location[] a, final int first, final int last) {
        if (first < last) {
            int q = xPartition(a, first, last); // Partition the array
            xQuickSort(a, first, q - 1); // Recursively sort the left subarray
            xQuickSort(a, q + 1, last); // Recursively sort the right subarray
        }
    }

    // Method to find the closest pair of points using divide and conquer
    public double closestPair(final Location[] a, final int indexNum) {
        // Create a subarray to work with
        Location[] divideArray = new Location[indexNum];
        System.arraycopy(a, 0, divideArray, 0, indexNum);
        int divideX = indexNum / 2; // Find the midpoint
        Location[] leftArray = new Location[divideX];
        Location[] rightArray = new Location[indexNum - divideX];

        // Base case for small arrays
        if (indexNum <= 3) {
            return bruteForce(divideArray); // Use brute force for small number of points
        }

        // Split the array into left and right halves
        System.arraycopy(divideArray, 0, leftArray, 0, divideX);
        System.arraycopy(divideArray, divideX, rightArray, 0, indexNum - divideX);

        // Recursively find the minimum distances in both halves
        double minLeftArea = closestPair(leftArray, divideX);
        double minRightArea = closestPair(rightArray, indexNum - divideX);
        double minValue = Math.min(minLeftArea, minRightArea); // Minimum distance found so far

        // Check points in the strip around the dividing line
        for (int i = 0; i < indexNum; i++) {
            double xGap = Math.abs(divideArray[divideX].x - divideArray[i].x);
            if (xGap < minValue) {
                Main.setSecondCount(secondCount + 1); // Update second count
            }
        }

        // Create an array for points within the strip
        Location[] firstWindow = new Location[secondCount];
        int k = 0;
        for (int i = 0; i < indexNum; i++) {
            double xGap = Math.abs(divideArray[divideX].x - divideArray[i].x);
            if (xGap < minValue) {
                firstWindow[k] = divideArray[i]; // Add point to the strip
                k++;
            }
        }

        // Check for the closest pair within the strip
        double length;
        for (int i = 0; i < secondCount - 1; i++) {
            for (int j = i + 1; j < secondCount; j++) {
                double xGap = Math.abs(firstWindow[i].x - firstWindow[j].x);
                double yGap = Math.abs(firstWindow[i].y - firstWindow[j].y);
                if (yGap < minValue) {
                    length = Math.sqrt(xGap * xGap + yGap * yGap); // Calculate distance
                    if (length < minValue) {
                        minValue = length; // Update minimum distance
                        if (length < minNum) {
                            Main.setMinNum(length); // Update global minimum distance
                            point1 = firstWindow[i]; // Update closest points
                            point2 = firstWindow[j];
                        }
                    }
                }
            }
        }
        Main.setSecondCount(0); // Reset second count for next call
        return minValue; // Return the minimum distance found
    }

    // Brute force method to find the closest pair of points for small arrays
    public double bruteForce(final Location[] arrayParam) {
        double minValue = Double.MAX_VALUE; // Initialize minimum distance
        double length;

        // Check all pairs of points
        for (int i = 0; i < arrayParam.length - 1; i++) {
            for (int j = i + 1; j < arrayParam.length; j++) {
                double xGap = arrayParam[i].x - arrayParam[j].x;
                double yGap = arrayParam[i].y - arrayParam[j].y;
                length = Math.sqrt(xGap * xGap + yGap * yGap); // Calculate distance
                if (length < minValue) {
                    minValue = length; // Update minimum distance
                    if (length < minNum) {
                        Main.setMinNum(length); // Update global minimum distance
                        point1 = arrayParam[i]; // Update closest points
                        point2 = arrayParam[j];
                    }
                }
            }
        }
        return minValue; // Return the minimum distance found
    }

    // Main method to execute the program
    public static void main(final String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read number of points
        Main cp = new Main(n); // Create Main object with number of points

        // Read points from input
        for (int i = 0; i < n; i++) {
            double x = scanner.nextDouble();
            double y = scanner.nextDouble();
            cp.array[i] = cp.buildLocation(x, y); // Build location objects
        }

        // Sort the array of locations based on x-coordinate
        cp.xQuickSort(cp.array, 0, cp.array.length - 1);
        // Find the closest pair of points
        double result = cp.closestPair(cp.array, cp.array.length);
        
        // Output the closest pair of points and the minimum distance
        System.out.println("(" + cp.point1.x + ", " + cp.point1.y + ")");
        System.out.println("(" + cp.point2.x + ", " + cp.point2.y + ")");
        System.out.println("Minimum Distance : " + result);
        scanner.close(); // Close the scanner
    }
}
