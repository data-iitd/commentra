import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine(); // Consume the newline after the last integer
        String S = scanner.nextLine();

        int segCnt = 0;
        for (int i = 0; i < N - 1; i++) {
            if (S.charAt(i) != S.charAt(i + 1)) {
                segCnt++;
            }
        }

        int curHappy = N - 1 - segCnt;

        if (2 * K >= segCnt) {
            System.out.println(N - 1);
        } else {
            System.out.println(curHappy + 2 * K);
        }
    }
}

