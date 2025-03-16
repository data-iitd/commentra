import java.util.Scanner;

public class Main {
    static final int LEN = 300;
    static final int TRUE = 1;
    static final int FALSE = -1;
    static int n;
    static int[] A = new int[LEN];
    static int flag;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        int q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            int M = scanner.nextInt();
            flag = FALSE;

            solve(-1, M);
            if (flag == TRUE) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }

        scanner.close();
    }

    static int solve(int i, int m) {
        if (i >= n) return FALSE;
        else if (m < 0) return FALSE;
        else if (m == 0 || m - A[i + 1] == 0) {
            flag = TRUE;
            return TRUE;
        } else {
            // not use A[i]
            solve(i + 1, m);
            // use A[i]
            solve(i + 1, m - A[i]);
        }
        return FALSE; // Added return statement to avoid compilation error
    }
}

// <END-OF-CODE>
