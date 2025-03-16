
import java.util.Scanner;

public class s108967797{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // ri() reads an integer from standard input.
        int ri() {
            return sc.nextInt();
        }

        // ave(s) calculates the average of a slice of float64 values.
        double ave(double[] s) {
            double sum = 0;
            for (double v : s) {
                sum += v;
            }
            return sum / s.length;
        }

        // diff(a, b) calculates the absolute difference between two float64 values.
        double diff(double a, double b) {
            return Math.abs(a - b);
        }

        int n = ri(); // Reads the number of elements.
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = ri(); // Reads n integers into a float64 slice.
        }

        // Uncommenting the following line will print the slice for debugging purposes.
        // System.out.println(Arrays.toString(a));

        double ave = ave(a); // Calculates the average of the slice.

        double minDiff = Double.MAX_VALUE;
        int ansIndex = -1;
        for (int i = 0; i < n; i++) {
            double diff = diff(a[i], ave); // Calculates the absolute difference between each element and the average.
            if (diff < minDiff) {
                minDiff = diff;
                ansIndex = i;
            }
        }
        System.out.println(ansIndex); // Outputs the index with the smallest difference.
    }
}
