

import java.util.Scanner;

/**
 * For a set of points in a coordinates system (10000 maximum), ClosestPair
 * class calculates the two closest points.
 */
public final class ClosestPair {

    /**
     * Number of points
     */
    int numberPoints;
    /**
     * Input data, maximum 10000.
     */
    Location[] array;
    /**
     * Minimum point coordinate.
     */
    Location point1 = null;
    /**
     * Minimum point coordinate.
     */
    Location point2 = null;
    /**
     * Minimum point length.
     */
    private static double minNum = Double.MAX_VALUE;

    public static void setMinNum(double minNum) {
        ClosestPair.minNum = minNum;
    }

    public static void setSecondCount(int secondCount) {
        ClosestPair.secondCount = secondCount;
    }

    /**
     * secondCount
     */
    private static int secondCount = 0;

    /**
     * Constructor.
     */
    ClosestPair(int points) {
        numberPoints = points;
        array = new Location[numberPoints];
    }

    /**
     * Location class is an auxiliary type to keep points coordinates.
     */
    public static class Location {
        double x;
        double y;

        /**
         * @param xpar (IN Parameter) x coordinate <br>
         * @param ypar (IN Parameter) y coordinate <br>
         */
        Location(final double xpar, final double ypar) {
            this.x = xpar;
            this.y = ypar;
        }
    }

    public Location buildLocation(double x, double y) {
        return new Location(x, y);
    }

    /**
     * xPartition function: arrange x-axis.
     *
     * @param a (IN Parameter) array of points <br>
     * @param first (IN Parameter) first point <br>
     * @param last (IN Parameter) last point <br>
     * @return pivot index
     */
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

    /**
     * xQuickSort function: //x-axis Quick Sorting.
     *
     * @param a (IN Parameter) array of points <br>
     * @param first (IN Parameter) first point <br>
     * @param last (IN Parameter) last point <br>
     */
    public void xQuickSort(final Location[] a, final int first, final int last) {
        if (first < last) {
            int q = xPartition(a, first, last);
            xQuickSort(a, first, q - 1);
            xQuickSort(a, q + 1, last);
        }
    }

    /**
     * closestPair function: find closest pair.
     *
     * @param a (IN Parameter) array stored before divide <br>
     * @param indexNum (IN Parameter) number coordinates divideArray <br>
     * @return minimum distance <br>
     */
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
                ClosestPair.setSecondCount(secondCount + 1);
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
                            ClosestPair.setMinNum(length);
                            point1 = firstWindow[i];
                            point2 = firstWindow[j];
                        }
                    }
                }
            }
        }
        ClosestPair.setSecondCount(0);
        return minValue;
    }

    /**
     * bruteForce function: When the number of coordinates is less than 3.
     *
     * @param arrayParam (IN Parameter) array stored before divide <br>
     * @return <br>
     */
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
                        ClosestPair.setMinNum(length);
                        point1 = arrayParam[i];
                        point2 = arrayParam[j];
                    }
                }
            }
        }
        return minValue;
    }

    /**
     * main function: execute class.
     *
     * @param args (IN Parameter) <br>
     */
    public static void main(final String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        ClosestPair cp = new ClosestPair(n);
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
}
