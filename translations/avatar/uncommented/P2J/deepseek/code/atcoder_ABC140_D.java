import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        String S = scanner.nextLine();
        
        int segCnt = 0;
        for (int i = 0; i < N - 1; i++) {
            if (S.charAt(i) != S.charAt(i + 1)) {
                segCnt++;
            }
        }
        
        int curHappy = N - 1 - segCnt;
        int ans;
        if (2 * K >= segCnt) {
            ans = N - 1;
        } else {
            ans = curHappy + 2 * K;
        }
        
        System.out.println(ans);
    }
}
