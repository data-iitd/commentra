import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int inning = 0;
        while (inning < n) {
            System.out.println(calc_score());
            inning++;
        }
    }

    public static int calc_score() {
        int out = 0;
        String str = sc.next();
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
            str = sc.next();
        }
        return score;
    }
}

