import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        double[] x = new double[N];
        for (int i = 0; i < N; i++) {
            String s = sc.next();
            if (s.equals("JPY")) {
                x[i] = 1.0;
            } else if (s.equals("BTC")) {
                x[i] = 380000.0;
            } else {
                x[i] = Double.parseDouble(s);
            }
        }
        System.out.println(sum(x));
    }

    public static double sum(double[] x) {
        double sum = 0.0;
        for (double d : x) {
            sum += d;
        }
        return sum;
    }
}
