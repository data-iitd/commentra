import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextDouble();
        }
        
        double average = average(a);
        
        double minDiff = Double.MAX_VALUE;
        int ansIndex = -1;
        for (int i = 0; i < n; i++) {
            double diff = Math.abs(a[i] - average);
            if (diff < minDiff) {
                minDiff = diff;
                ansIndex = i;
            }
        }
        
        System.out.println(ansIndex);
        sc.close();
    }

    private static double average(double[] s) {
        double sum = 0;
        for (double v : s) {
            sum += v;
        }
        return sum / s.length;
    }
}
