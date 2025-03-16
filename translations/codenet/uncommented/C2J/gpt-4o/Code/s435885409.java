import java.util.Scanner;

public class Main {
    public static int calcScore() {
        int out = 0;
        String str;
        int score = 0;
        int base = 0;
        Scanner scanner = new Scanner(System.in);

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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int inning = 0;

        while (inning < n) {
            System.out.println(calcScore());
            inning++;
        }
    }
}

// <END-OF-CODE>
