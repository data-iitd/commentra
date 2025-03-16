import java.util.Scanner;

public class Main {
    // Scanner for reading input
    private static final Scanner sc = new Scanner(System.in);

    // Method to read an integer from standard input
    private static int ri() {
        return sc.nextInt();
    }

    // Method to calculate the average of an array of doubles
    private static double ave(double[] s) {
        double sum = 0;
        for (double v : s) {
            sum += v;
        }
        return sum / s.length;
    }

    // Method to calculate the absolute difference between two doubles
    private static double diff(double a, double b) {
        return Math.abs(a - b);
    }

    // Main method is the entry point of the program
    public static void main(String[] args) {
        int n = ri(); // Reads the number of elements
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = ri(); // Reads n integers into a double array
        }

        double average = ave(a); // Calculates the average of the array

        double minDiff = Double.MAX_VALUE;
        int ansIndex = -1;
        for (int i = 0; i < a.length; i++) {
            double difference = diff(a[i], average); // Calculates the absolute difference between each element and the average
            if (difference < minDiff) {
                minDiff = difference;
                ansIndex = i;
            }
        }
        System.out.println(ansIndex); // Outputs the index with the smallest difference
    }
}

// <END-OF-CODE>
