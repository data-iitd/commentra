public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        double a;
        double ave = 0;
        int i;

        for (i = 0; i < 5; i++) {
            a = scanner.nextDouble();
            if (a <= 40) {
                ave += 40;
            } else {
                ave += a;
            }
        }
        // System.out.printf("%.0f\n", ave);

        ave /= 5.0;

        System.out.printf("%.0f\n", ave);
    }
}
