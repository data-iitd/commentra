import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        String S = scanner.nextLine();

        boolean aaaa = false;
        if (K >= 15) {
            aaaa = true;
        } else if (Math.pow(2, K) >= N) {
            aaaa = true;
        }
        if (aaaa) {
            char minChar = S.charAt(0);
            for (int i = 1; i < N; i++) {
                if (S.charAt(i) < minChar) {
                    minChar = S.charAt(i);
                }
            }
            System.out.println((char) (minChar * N));
            return;
        }

        String result = getLastDict(S);
        if (K == 1) {
            System.out.println(result);
        } else {
            int count = 0;
            char firstChar = result.charAt(0);
            for (int i = 0; i < result.length(); i++) {
                if (result.charAt(i) == firstChar) {
                    count++;
                } else {
                    break;
                }
            }
            if (count * Math.pow(2, K - 1) >= N) {
                System.out.println(String.valueOf(firstChar).repeat(N));
            } else {
                String prefix = String.valueOf(firstChar).repeat((int) (count * (Math.pow(2, K - 1) - 1)));
                result = prefix + result;
                System.out.println(result.substring(0, N));
            }
        }
    }

    public static String getLastDict(String s) {
        StringBuilder U = new StringBuilder(s).append(new StringBuilder(s).reverse());
        char c = minChar(s);
        int p = U.indexOf(String.valueOf(c));
        int minIndex = p;
        p += 1;
        while (p <= s.length()) {
            if (U.charAt(p) == c) {
                if (checkNormalDict(U.toString(), minIndex, p)) {
                    minIndex = p;
                }
            }
            p++;
        }
        return U.substring(minIndex, minIndex + s.length());
    }

    public static boolean checkNormalDict(String u, int pointer1, int pointer2) {
        for (int i = 0; i < u.length(); i++) {
            if (u.charAt(pointer1 + i) > u.charAt(pointer2 + i)) {
                return true;
            } else if (u.charAt(pointer1 + i) < u.charAt(pointer2 + i)) {
                return false;
            }
        }
        return false;
    }

    public static char minChar(String s) {
        char minChar = s.charAt(0);
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) < minChar) {
                minChar = s.charAt(i);
            }
        }
        return minChar;
    }
}
