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
            for (int i = 1; i < S.length(); i++) {
                if (S.charAt(i) < minChar) {
                    minChar = S.charAt(i);
                }
            }
            System.out.println((int) (minChar * N));
            return;
        }

        String getLastDict(String sStr) {
            String U = sStr + new StringBuilder(sStr).reverse().toString();
            char c = sStr.charAt(0);
            int p = U.indexOf(c);
            int minindex = p;
            p += 1;
            while (p <= N) {
                if (U.charAt(p) == c) {
                    if (checkNormalDict(U, minindex, p)) {
                        minindex = p;
                    }
                }
                p += 1;
            }
            return U.substring(minindex, minindex + N);
        }

        boolean checkNormalDict(String u, int pointer1, int pointer2) {
            for (int i = 0; i < N; i++) {
                if (u.charAt(pointer1 + i) > u.charAt(pointer2 + i)) {
                    return true;
                } else if (u.charAt(pointer1 + i) < u.charAt(pointer2 + i)) {
                    return false;
                }
            }
            return false;
        }

        S = getLastDict(S);

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

            if (count * Math.pow(2, K - 1) >= N) {
                System.out.println(String.valueOf(firstChar).repeat(N));
            } else {
                String newS = String.valueOf(firstChar).repeat(count * ((int) Math.pow(2, K - 1) - 1)) + S;
                System.out.println(newS.substring(0, N));
            }
        }
    }
}
