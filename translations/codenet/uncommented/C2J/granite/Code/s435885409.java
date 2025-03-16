
import java.util.Scanner;

public class s435885409{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.println(calc_score());
        }
    }

    public static int calc_score() {
        int out = 0;
        String str = "";
        int score = 0;
        int base = 0;

        while (out < 3) {
            str = scanner.next();
            if (str.equals("OUT")) {
                out++;
            } else if (str.equals("HIT")) {
                if (base == 3) {
                    score++;
                } else {
                    base++;
                }
            } else if (str.equals("HOMERUN")) {
                score += (base + 1);
                base = 0;
            }
        }

        return score;
    }
}

