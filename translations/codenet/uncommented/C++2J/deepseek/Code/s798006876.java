import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int MAX_N = 1000;
        int[] data = new int[MAX_N];

        while (scanner.hasNextInt()) {
            int m = scanner.nextInt();
            int nmi = scanner.nextInt();
            int nma = scanner.nextInt();

            if (nmi == 0) {
                break;
            }

            for (int i = 0; i < m; i++) {
                data[i] = scanner.nextInt();
            }

            int ma = 0;
            int ans = 0;
            for (int i = nmi - 1; i < nma; i++) {
                if (ma <= data[i] - data[i + 1]) {
                    ans = i + 1;
                    ma = data[i] - data[i + 1];
                }
            }

            System.out.println(ans);
        }

        scanner.close();
    }
}
