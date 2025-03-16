import java.util.Scanner;

class Problem {
    int number, bonus;

    Problem(int number, int bonus) {
        this.number = number;
        this.bonus = bonus;
    }
}

public class Main {
    // min returns the smaller of two integers.
    static int min(int a, int b) {
        return a >= b ? b : a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int D = scanner.nextInt();
        int G = scanner.nextInt();
        Problem[] problems = new Problem[D];

        for (int i = 0; i < D; i++) {
            int number = scanner.nextInt();
            int bonus = scanner.nextInt();
            problems[i] = new Problem(number, bonus);
        }

        int ans = 10000;
        for (int bit = 0; bit < (1 << D); bit++) {
            int score = 0;
            int solved = 0;
            boolean ok = false;

            for (int j = 0; j < D; j++) {
                if ((bit & (1 << j)) != 0) {
                    score += (j + 1) * 100 * problems[j].number + problems[j].bonus;
                    solved += problems[j].number;
                }
            }

            if (score < G) {
                int j;
                for (j = D - 1; j >= 0; j--) {
                    if ((bit & (1 << j)) == 0) {
                        break;
                    }
                }
                for (int k = 0; k < problems[j].number; k++) {
                    score += (j + 1) * 100;
                    solved++;
                    if (score >= G) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    score += problems[j].bonus;
                    if (score >= G) {
                        ok = true;
                    }
                }
            } else {
                ok = true;
            }

            if (ok) {
                ans = min(ans, solved);
            }
        }
        System.out.println(ans);
    }
}
// <END-OF-CODE>
