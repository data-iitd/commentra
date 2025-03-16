import java.util.Scanner;

public class BaseballScoreCalculator {
    
    public static int calcScore(Scanner scanner) {
        int out = 0;
        int score = 0;
        int base = 0;

        // Read the number of outs and update the score and base accordingly
        while (out < 3) {
            String str = scanner.next();
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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int inning = 0;

        // Loop through each inning and calculate the score
        while (inning < n) {
            System.out.println(calcScore(scanner));
            inning++;
        }

        scanner.close();
    }
}

// <END-OF-CODE>
