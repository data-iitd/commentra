import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize variables
        int H = scanner.nextInt();
        int W = scanner.nextInt();
        int N = scanner.nextInt();
        int s_r = scanner.nextInt();
        int s_c = scanner.nextInt();
        String S = scanner.next();
        String T = scanner.next();
        boolean Judge = false;

        // Initialize variables for string S
        int S_L = 0, S_R = 0, S_U = 0, S_D = 0;

        // Iterate through string S
        for (int x = 0; x < N; x++) {
            // Check current character in S
            char currentChar = S.charAt(x);
            if (currentChar == 'L') {
                S_L++;
                // Check condition for 'L'
                if (S_L - T_R - s_c == 0) {
                    Judge = true;
                }
            } else if (currentChar == 'R') {
                S_R++;
                // Check condition for 'R'
                if (s_c + (S_R - T_L) == W + 1) {
                    Judge = true;
                }
            } else if (currentChar == 'U') {
                S_U++;
                // Check condition for 'U'
                if (S_U - T_D - s_r == 0) {
                    Judge = true;
                }
            } else if (currentChar == 'D') {
                S_D++;
                // Check condition for 'D'
                if (s_r + (S_D - T_U) == H + 1) {
                    Judge = true;
                }
            }
        }

        // Initialize variables for string T
        int T_L = 0, T_R = 0, T_U = 0, T_D = 0;

        // Iterate through string T and adjust variables accordingly
        for (int x = 0; x < N; x++) {
            // Check current character in T
            char currentChar = T.charAt(x);
            if (currentChar == 'L') {
                // Adjust T_L variable
                if (S_R - T_L + s_c != 1) {
                    T_L++;
                }
            }
            if (currentChar == 'R') {
                // Adjust T_R variable
                if (s_c + (T_R - S_L) != W) {
                    T_R++;
                }
            }
            if (currentChar == 'U') {
                // Adjust T_U variable
                if (S_D - T_U + s_r != 1) {
                    T_U++;
                }
            }
            if (currentChar == 'D') {
                // Adjust T_D variable
                if (s_r + (T_D - S_U) != H) {
                    T_D++;
                }
            }
        }

        // Check final condition
        if (Judge) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }

        scanner.close();
    }
}
// <END-OF-CODE>
