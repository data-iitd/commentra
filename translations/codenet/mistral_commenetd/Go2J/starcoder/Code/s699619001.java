import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int D = sc.nextInt();
        int G = sc.nextInt();
        problem[] problems = new problem[D];
        for (int i = 0; i < D; i++) {
            int number = sc.nextInt();
            int bonus = sc.nextInt();
            problems[i] = new problem(number, bonus);
        }
        int ans = 10000;
        for (int bit = 0; bit < (1 << D); bit++) {
            int score = 0;
            int solved = 0;
            boolean ok = false;
            for (int j = 0; j < D; j++) {
                if ((bit & (1 << j))!= 0) {
                    score += (j + 1) * 100 * problems[j].number + problems[j].bonus;
                    solved += problems[j].number;
                }
            }
            if (score < G) {
                int j;
                for (j = D - 1; j >= 0; j--) {
                    if ((bit & (1 << j)) == 0) {
                        for (int k = 0; k < problems[j].number; k++) {
                            score += (j + 1) * 100;
                            solved++;
                            if (score >= G) {
                                ok = true;
                                break;
                            }
                        }
                        if (problems[j].bonus > 0) {
                            score += problems[j].bonus;
                            solved++;
                            if (score >= G) {
                                ok = true;
                                break;
                            }
                        }
                    }
                    if (ok) {
                        break;
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

class problem {
    int number, bonus;
    problem(int number, int bonus) {
        this.number = number;
        this.bonus = bonus;
    }
}

