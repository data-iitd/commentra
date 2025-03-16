import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Reads the number of elements.
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextDouble(); // Reads n integers into a double array.
        }
        // Uncommenting the following line will print the array for debugging purposes.
        // System.out.println(Arrays.toString(a));

        double ave = average(a); // Calculates the average of the array.

        double minDiff = 999999.9;
        int ansIndex = -1;
        for (int i = 0; i < n; i++) {
            double diff = Math.abs(a[i] - ave); // Calculates the absolute difference between each element and the average.
            if (diff < minDiff) {
                minDiff = diff;
                ansIndex = i;
            }
        }
        System.out.println(ansIndex); // Outputs the index with the smallest difference.
    }

    // average function calculates the average of an array of double values.
    public static double average(double[] array) {
        double sum = 0;
        for (double value : array) {
            sum += value;
        }
        return sum / array.length;
    }
}
