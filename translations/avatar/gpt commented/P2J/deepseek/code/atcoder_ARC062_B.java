import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        char[] s = input.toCharArray();

        int numG = 0, numP = 0;
        int score = 0;

        for (char x : s) {
            if (x == 'g') {
                if (numG - numP > 0) {
                    score += 1;
                    numP += 1;
                } else {
                    numG += 1;
                }
            } else if (x == 'p') {
                if (numG - numP > 0) {
                    numP += 1;
                } else {
                    score -= 1;
                    numG += 1;
                }
            }
        }

        System.out.println(score);
    }
}
