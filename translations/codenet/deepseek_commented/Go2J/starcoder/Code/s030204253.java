import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextDouble();
        }
        while (n > 1) {
            double[] na = new double[n - 2];
            for (int i = 2; i < n; i++) {
                na[i - 2] = a[i];
            }
            na[n - 3] = (a[0] + a[1]) / 2;
            a = na;
            n -= 2;
        }
        System.out.println(a[0]);
    }
}

