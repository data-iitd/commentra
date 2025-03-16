import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        String T = scanner.next();
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
        scanner.close();
    }
}

// <END-OF-CODE>
