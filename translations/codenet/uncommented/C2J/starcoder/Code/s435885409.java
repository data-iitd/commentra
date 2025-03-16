import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int inning = 0;
        while (inning < n) {
            System.out.println(calc_score());
            inning++;
        }
    }

    public static int calc_score() {
        int out = 0;
        String str = in.next();
        int score = 0;
        int base = 0;
        while (out < 3) {
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
            str = in.next();
        }
        return score;
    }
}

