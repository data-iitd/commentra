
import java.util.Scanner;

public class s699619001{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int D = scanner.nextInt();
        int G = scanner.nextInt();
        int[] number = new int[D];
        int[] bonus = new int[D];
        for (int i = 0; i < D; i++) {
            number[i] = scanner.nextInt();
            bonus[i] = scanner.nextInt();
        }
        int ans = 10000;
        for (int bit = 0; bit < (1 << D); bit++) {
            int score = 0;
            int solved = 0;
            boolean ok = false;
            for (int j = 0; j < D; j++) {
                if ((bit & (1 << j))!= 0) {
                    score += (j + 1) * 100 * number[j] + bonus[j];
                    solved += number[j];
                }
            }
            if (score < G) {
                int j = D - 1;
                while ((bit & (1 << j))!= 0) {
                    j--;
                }
                for (int k = 0; k < number[j]; k++) {
                    score += (j + 1) * 100;
                    solved++;
                    if (score >= G) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    score += bonus[j];
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
