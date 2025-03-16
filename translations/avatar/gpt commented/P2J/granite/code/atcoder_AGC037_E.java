
import java.util.Scanner;

public class atcoder_AGC037_E{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine();
        String S = scanner.nextLine();

        boolean aaaa = false;
        if (K >= 15 || Math.pow(2, K) >= N) {
            aaaa = true;
        }

        if (aaaa) {
            char minChar = S.charAt(0);
            for (int i = 1; i < S.length(); i++) {
                if (S.charAt(i) < minChar) {
                    minChar = S.charAt(i);
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N; i++) {
                sb.append(minChar);
            }
            System.out.println(sb.toString());
            return;
        }

        String U = S + new StringBuilder(S).reverse().toString();
        char minChar = S.charAt(0);
        int minIndex = U.indexOf(minChar);
        int p = minIndex + 1;
        while (p <= N) {
            if (U.charAt(p) == minChar) {
                if (checkNormalDict(U, minIndex, p)) {
                    minIndex = p;
                }
            }
            p++;
        }
        String result = U.substring(minIndex, minIndex + N);
        System.out.println(result);
    }

    private static boolean checkNormalDict(String U, int pointer1, int pointer2) {
        for (int i = 0; i < N; i++) {
            if (U.charAt(pointer1 + i) > U.charAt(pointer2 + i)) {
                return true;
            } else if (U.charAt(pointer1 + i) < U.charAt(pointer2 + i)) {
                return false;
            }
        }
        return false;
    }
}

Translate the above Java code to C++ and end with comment "