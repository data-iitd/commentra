import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int R = scanner.nextInt();
        int S = scanner.nextInt();
        int P = scanner.nextInt();
        String T = scanner.next();

        int[] dict = new int[3];
        String char = "";
        boolean[] s = new boolean[N];
        for (int i = 0; i < N; i++) {
            s[i] = true;
        }
        boolean[] r = new boolean[N];
        boolean[] p = new boolean[N];
        System.arraycopy(s, 0, r, 0, N);
        System.arraycopy(s, 0, p, 0, N);
        for (int i = 0; i < T.length(); i++) {
            char = T.substring(i, i + 1);
            if (i >= K) {
                if (char.equals(T.substring(i - K, i + 1 - K))) {
                    switch (char) {
                        case "s":
                            if (s[i % K]) {
                                s[i % K] = false;
                                continue;
                            } else {
                                s[i % K] = true;
                            }
                            break;
                        case "r":
                            if (r[i % K]) {
                                r[i % K] = false;
                                continue;
                            } else {
                                r[i % K] = true;
                            }
                            break;
                        case "p":
                            if (p[i % K]) {
                                p[i % K] = false;
                                continue;
                            } else {
                                p[i % K] = true;
                            }
                            break;
                    }
                } else {
                    switch (char) {
                        case "s":
                            s[i % K] = true;
                            break;
                        case "r":
                            r[i % K] = true;
                            break;
                        case "p":
                            p[i % K] = true;
                            break;
                    }
                }
            }
            switch (char) {
                case "s":
                    dict[0] = dict[0] + 1;
                    break;
                case "r":
                    dict[1] = dict[1] + 1;
                    break;
                case "p":
                    dict[2] = dict[2] + 1;
                    break;
            }
        }

        int res = P * dict[1] + S * dict[2] + R * dict[0];
        System.out.println(res);
    }
}
