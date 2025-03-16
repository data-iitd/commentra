import java.util.Scanner;
public final class Main {
    // Number of points
    int numberPoints;
    // Array to store locations
    Location[] array;
    // To store the closest pair of points
    Location point1 = null;
    Location point2 = null;
    // To store the minimum distance found so far
    private static double minNum = Double.MAX_VALUE;
    // To keep track of the number of comparisons made
    private static int secondCount = 0;

    // Constructor to initialize the number of points and array
    public Main(int points) {
        numberPoints = points;
        array = new Location[numberPoints];
    }

    // Nested class to store location coordinates
    public static class Location {
        double x;
        double y;
        // Constructor to initialize the location with x and y coordinates
        Location(final double xpar, final double ypar) {
            this.x = xpar;
            this.y = ypar;
        }
    }

    // Method to build a new Location object
    public Location buildLocation(double x, double y) {
        return new Location(x, y);
    }

    // Method to partition the array based on x-coordinates for QuickSort
    public int xPartition(final Location[] a, final int first, final int last) {
        Location pivot = a[last];
        int i = first - 1;
        Location temp;
        for (int j = first; j <= last - 1; j++) {
            if (a[j].x <= pivot.x) {
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        i++;
        temp = a[i];
        a[i] = a[last];
        a[last] = temp;
        return i;
    }

    // Method to implement QuickSort using xPartition
    public void xQuickSort(final Location[] a, final int first, final int last) {
        if (first < last) {
            int q = xPartition(a, first, last);
            xQuickSort(a, first, q - 1);
            xQuickSort(a, q + 1, last);
        }
    }

    // Method to find the closest pair of points recursively
    public double closestPair(final Location[] a, final int indexNum) {
        Location[] divideArray = new Location[indexNum];
        System.arraycopy(a, 0, divideArray, 0, indexNum);
        int divideX = indexNum / 2;
        Location[] leftArray = new Location[divideX];
        Location[] rightArray = new Location[indexNum - divideX];
        if (indexNum <= 3) {
            return bruteForce(divideArray);
        }
        System.arraycopy(divideArray, 0, leftArray, 0, divideX);
        System.arraycopy(divideArray, divideX, rightArray, 0, indexNum - divideX);
        double minLeftArea = closestPair(leftArray, divideX);
        double minRightArea = closestPair(rightArray, indexNum - divideX);
        double minValue = Math.min(minLeftArea, minRightArea);
        for (int i = 0; i < indexNum; i++) {
            double xGap = Math.abs(divideArray[divideX].x - divideArray[i].x);
            if (xGap < minValue) {
                secondCount++;
            }
        }
        Location[] firstWindow = new Location[secondCount];
        int k = 0;
        for (int i = 0; i < indexNum; i++) {
            double xGap = Math.abs(divideArray[divideX].x - divideArray[i].x);
            if (xGap < minValue) {
                firstWindow[k] = divideArray[i];
                k++;
            }
        }
        double length;
        for (int i = 0; i < secondCount - 1; i++) {
            for (int j = i + 1; j < secondCount; j++) {
                double xGap = Math.abs(firstWindow[i].x - firstWindow[j].x);
                double yGap = Math.abs(firstWindow[i].y - firstWindow[j].y);
                if (yGap < minValue) {
                    length = Math.sqrt(xGap * xGap + yGap * yGap);
                    if (length < minValue) {
                        minValue = length;
                        if (length < minNum) {
                            setMinNum(length);
                            point1 = firstWindow[i];
                            point2 = firstWindow[j];
                        }
                    }
                }
            }
        }
        secondCount = 0; // Reset the counter for the next call
        return minValue;
    }

    // Method to find the closest pair of points using brute-force approach
    public double bruteForce(final Location[] arrayParam) {
        double minValue = Double.MAX_VALUE;
        double length;
        for (int i = 0; i < arrayParam.length - 1; i++) {
            for (int j = i + 1; j < arrayParam.length; j++) {
                double xGap = arrayParam[i].x - arrayParam[j].x;
                double yGap = arrayParam[i].y - arrayParam[j].y;
                length = Math.sqrt(xGap * xGap + yGap * yGap);
                if (length < minValue) {
                    minValue = length;
                    if (length < minNum) {
                        setMinNum(length);
                        point1 = arrayParam[i];
                        point2 = arrayParam[j];
                    }
                }
            }
        }
        return minValue;
    }

    // Main method to read input, sort points, find closest pair, and print results
    public static void main(final String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Main cp = new Main(n);
        for (int i = 0; i < n; i++) {
            double x = scanner.nextDouble();
            double y = scanner.nextDouble();
            cp.array[i] = cp.buildLocation(x, y);
        }
        cp.xQuickSort(cp.array, 0, cp.array.length - 1);
        double result = cp.closestPair(cp.array, cp.array.length);
        System.out.println("(" + cp.point1.x + ", " + cp.point1.y + ")");
        System.out.println("(" + cp.point2.x + ", " + cp.point2.y + ")");
        System.out.println("Minimum Distance : " + result);
        scanner.close();
    }

    // Static method to set the minimum number
    public static void setMinNum(double minNum) {
        Main.minNum = minNum;
    }

    // Static method to set the second count
    public static void setSecondCount(int secondCount) {
        Main.secondCount = secondCount;
    }
}
