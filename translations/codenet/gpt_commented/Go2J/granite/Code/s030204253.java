
import java.util.Arrays;
import java.util.Scanner;

public class s030204253{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextDouble();
        }
        for (int i = 0; i < n - 1; i++) {
            Arrays.sort(a);
            double[] na = new double[a.length - 1];
            System.arraycopy(a, 2, na, 0, na.length);
            na[na.length - 1] = (a[0] + a[1]) / 2;
            a = na;
        }
        System.out.println(a[0]);
    }
}

