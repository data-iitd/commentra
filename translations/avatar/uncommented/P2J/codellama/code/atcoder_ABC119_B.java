import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        double[] x = new double[N];
        for (int i = 0; i < N; i++) {
            String s = sc.next();
            if (s.contains("JPY")) {
                x[i] = Double.parseDouble(s.replace("JPY", ""));
            } else if (s.contains("BTC")) {
                x[i] = Double.parseDouble(s.replace("BTC", "")) * 380000.0;
            }
        }
        double sum = 0;
        for (int i = 0; i < N; i++) {
            sum += x[i];
        }
        System.out.println(sum);
    }
}

