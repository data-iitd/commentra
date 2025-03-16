import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = gi(scanner);
        int K = gi(scanner);
        String S = gw(scanner);
        
        int seg_cnt = 0;
        for (int i = 0; i < N - 1; i++) {
            if (S.charAt(i) != S.charAt(i + 1)) {
                seg_cnt++;
            }
        }
        
        int cur_happy = N - 1 - seg_cnt;
        int ans;
        if (2 * K >= seg_cnt) {
            ans = N - 1;
        } else {
            ans = cur_happy + 2 * K;
        }
        
        System.out.println(ans);
    }

    private static int gi(Scanner scanner) {
        return Integer.parseInt(scanner.next());
    }

    private static String gw(Scanner scanner) {
        return scanner.next();
    }
}

// <END-OF-CODE>
