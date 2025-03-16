public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        int D = scanner.nextInt();
        int E = scanner.nextInt();
        int F = scanner.nextInt();

        int m1 = 0, m2 = 0;
        double maxD = 0.0;
        for (int i = 0; 100 * A * i <= F; i++) {
            int mA = 100 * A * i;
            for (int j = 0; mA + 100 * B * j <= F; j++) {
                int mB = 100 * B * j;
                for (int k = 0; mA + mB + C * k <= F; k++) {
                    int mC = C * k;
                    for (int l = 0; mA + mB + mC + D * l <= F; l++) {
                        int mD = D * l;
                        if ((mA + mB) * E / 100 < mD + mC) {
                            break;
                        }
                        double d = (double) (mD + mC) / (double) (mA + mB + mC + mD);
                        if (d > maxD) {
                            m1 = mA + mB + mC + mD;
                            m2 = mC + mD;
                            maxD = d;
                        }
                    }
                }
            }
        }
        if (m1 == 0) {
            m1 = 100 * A;
        }
        System.out.println(m1 + " " + m2);
    }
}
