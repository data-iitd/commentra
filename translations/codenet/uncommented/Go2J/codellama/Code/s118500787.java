
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();
        String T = sc.nextLine();
        int max = 0;
        for (int i = 0; i <= S.length() - T.length(); i++) {
            int c = 0;
            for (int j = 0; j < T.length(); j++) {
                if (S.charAt(i + j) == T.charAt(j)) {
                    c++;
                }
            }
            if (max < c) {
                max = c;
            }
        }
        System.out.println(T.length() - max);
    }
}

