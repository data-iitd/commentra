import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int D = scanner.nextInt();
        int G = scanner.nextInt();
        int[] numbers = new int[D];
        int[] bonuses = new int[D];
        for (int i = 0; i < D; i++) {
            numbers[i] = scanner.nextInt();
            bonuses[i] = scanner.nextInt();
        }

        int ans = Integer.MAX_VALUE;
        for (int bit = 0; bit < (1 << D); bit++) {
            int score = 0;
            int solved = 0;
            boolean ok = false;
            for (int j = 0; j < D; j++) {
                if ((bit & (1 << j)) != 0) {
                    score += (j + 1) * 100 * numbers[j] + bonuses[j];
                    solved += numbers[j];
                }
            }
            if (score < G) {
                int j;
                for (j = D - 1; j >= 0; j--) {
                    if ((bit & (1 << j)) == 0) {
                        break;
                    }
                }
                for (int k = 0; k < numbers[j]; k++) {
                    score += (j + 1) * 100;
                    solved++;
                    if (score >= G) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    score += bonuses[j];
                    if (score >= G) {
                        ok = true;
                    }
                }
            } else {
                ok = true;
            }
            if (ok) {
                ans = Math.min(ans, solved);
            }
        }
        System.out.println(ans);
    }
}
