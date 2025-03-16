
import java.util.Scanner;

public class s108967797{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextDouble();
        }

        double ave = 0;
        for (int i = 0; i < n; i++) {
            ave += a[i];
        }
        ave /= n;

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
}

// END-OF-CODE