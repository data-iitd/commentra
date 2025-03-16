import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextDouble();
        }
        
        for (int i = 0; i + 1 < n; i++) {
            Arrays.sort(a);
            double[] na = new double[a.length - 2];
            for (int j = 2; j < a.length; j++) {
                na[j - 2] = a[j];
            }
            na = Arrays.copyOf(na, na.length + 1);
            na[na.length - 1] = (a[0] + a[1]) / 2;
            a = na;
        }
        
        System.out.println(a[0]);
        scanner.close();
    }
}
// <END-OF-CODE>
