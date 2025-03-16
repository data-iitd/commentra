public class AverageCalculator {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        double ave = 0;
        for (int i = 0; i < 5; i++) {
            double a = scanner.nextDouble();
            if (a <= 40) {
                ave += 40;
            } else {
                ave += a;
            }
        }
        ave /= 5.0;
        System.out.printf("%.0f\n", ave);
    }
}
