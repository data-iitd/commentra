import java.util.Scanner;

public class BaseballScoreCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of innings: ");
        int n = scanner.nextInt();
        int inning = 0;

        while (inning < n) {
            int score = calcScore();
            System.out.println(score);
            inning++;
        }
    }

    public static int calcScore() {
        Scanner scanner = new Scanner(System.in);
        int out = 0;
        int score = 0;
        int base = 0;

        while (out < 3) {
            System.out.print("Enter the event for this at bat (HIT, HOMERUN or OUT): ");
            String event = scanner.next();

            if (event.equals("OUT")) {
                out++;
            } else if (event.equals("HIT")) {
                if (base == 3) {
                    score++;
                } else {
                    base++;
                }
            } else if (event.equals("HOMERUN")) {
                score += (base + 1);
                base = 0;
            }
        }

        return score;
    }
}
