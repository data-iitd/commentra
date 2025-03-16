
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int num_g = 0, num_p = 0, score = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'g') {
                if (num_g - num_p > 0) {
                    score++;
                    num_p++;
                } else {
                    score = score;
                    num_g++;
                }
            } else if (s.charAt(i) == 'p') {
                if (num_g - num_p > 0) {
                    score = score;
                    num_p++;
                } else {
                    score--;
                    num_g++;
                }
            }
        }
        System.out.println(score);
    }
}

