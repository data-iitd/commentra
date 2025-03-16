import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        char[] s = input.toCharArray();
        
        int num_g = 0, num_p = 0;
        int score = 0;
        
        for (char x : s) {
            if (x == 'g') {
                if (num_g - num_p > 0) {
                    score += 1;
                    num_p += 1;
                } else {
                    // score remains the same
                    num_g += 1;
                }
            } else if (x == 'p') {
                if (num_g - num_p > 0) {
                    // score remains the same
                    num_p += 1;
                } else {
                    score -= 1;
                    num_g += 1;
                }
            }
        }
        
        System.out.println(score);
        scanner.close();
    }
}
// <END-OF-CODE>
