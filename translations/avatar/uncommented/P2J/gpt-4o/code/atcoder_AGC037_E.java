import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        String S = scanner.next();
        boolean aaaa = false;

        if (K >= 15) {
            aaaa = true;
        } else if (Math.pow(2, K) >= N) {
            aaaa = true;
        }

        if (aaaa) {
            char minChar = findMinChar(S);
            System.out.println(String.valueOf(minChar).repeat(N));
            return;
        }

        S = getLastDict(S, N);
        if (K == 1) {
            System.out.println(S);
        } else {
            int count = 0;
            char firstChar = S.charAt(0);
            for (char c : S.toCharArray()) {
                if (c == firstChar) {
                    count++;
                } else {
                    break;
                }
            }
            if (count * (int) (Math.pow(2, K - 1)) >= N) {
                System.out.println(String.valueOf(firstChar).repeat(N));
            } else {
                StringBuilder result = new StringBuilder();
                result.append(String.valueOf(firstChar).repeat(count * ((int) (Math.pow(2, K - 1)) - 1)));
                result.append(S);
                System.out.println(result.substring(0, N));
            }
        }
    }

    private static String getLastDict(String sStr, int N) {
        String U = sStr + new StringBuilder(sStr).reverse().toString();
        char c = findMinChar(sStr);
        int p = U.indexOf(c);
        int minIndex = p;
        p++;

        while (p <= N) {
            if (U.charAt(p) == c) {
                if (checkNormalDict(U, minIndex, p, N)) {
                    minIndex = p;
                }
            }
            p++;
        }
        return U.substring(minIndex, minIndex + N);
    }

    private static boolean checkNormalDict(String u, int pointer1, int pointer2, int N) {
        for (int i = 0; i < N; i++) {
            if (u.charAt(pointer1 + i) > u.charAt(pointer2 + i)) {
                return true;
            } else if (u.charAt(pointer1 + i) < u.charAt(pointer2 + i)) {
                return false;
            }
        }
        return false;
    }

    private static char findMinChar(String s) {
        char minChar = s.charAt(0);
        for (char c : s.toCharArray()) {
            if (c < minChar) {
                minChar = c;
            }
        }
        return minChar;
    }
}
// <END-OF-CODE>
