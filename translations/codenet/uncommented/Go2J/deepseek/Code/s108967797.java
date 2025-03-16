import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextDouble();
        }

        double ave = average(a);

        double minDiff = Double.MAX_VALUE;
        int ansIndex = -1;
        for (int i = 0; i < n; i++) {
            double diff = Math.abs(a[i] - ave);
            if (diff < minDiff) {
                minDiff = diff;
                ansIndex = i;
            }
        }
        System.out.println(ansIndex);
    }

    private static double average(double[] a) {
        double sum = 0;
        for (double v : a) {
            sum += v;
        }
        return sum / a.length;
    }
}
