
import java.util.Scanner;

public class s934374308{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int R = scanner.nextInt();
        int S = scanner.nextInt();
        int P = scanner.nextInt();
        String T = scanner.next();

        int[] dict = new int[3];
        dict[0] = R;
        dict[1] = S;
        dict[2] = P;

        boolean[] s = new boolean[N];
        boolean[] r = new boolean[N];
        boolean[] p = new boolean[N];

        for (int i = 0; i < N; i++) {
            s[i] = true;
        }
        System.arraycopy(r, 0, s, 0, N);
        System.arraycopy(p, 0, s, 0, N);

        int res = 0;
        for (int i = 0; i < T.length(); i++) {
            char c = T.charAt(i);
            if (i >= K) {
                if (c == T.charAt(i - K)) {
                    switch (c) {
                        case's':
                            if (s[i % K]) {
                                s[i % K] = false;
                                continue;
                            } else {
                                s[i % K] = true;
                            }
                            break;
                        case 'r':
                            if (r[i % K]) {
                                r[i % K] = false;
                                continue;
                            } else {
                                r[i % K] = true;
                            }
                            break;
                        case 'p':
                            if (p[i % K]) {
                                p[i % K] = false;
                                continue;
                            } else {
                                p[i % K] = true;
                            }
                            break;
                    }
                } else {
                    switch (c) {
                        case's':
                            s[i % K] = true;
                            break;
                        case 'r':
                            r[i % K] = true;
                            break;
                        case 'p':
                            p[i % K] = true;
                            break;
                    }
                }
            }
            switch (c) {
                case's':
                    dict[0] += 1;
                    break;
                case 'r':
                    dict[1] += 1;
                    break;
                case 'p':
                    dict[2] += 1;
                    break;
            }
        }

        res = dict[0] * R + dict[1] * S + dict[2] * P;
        System.out.println(res);
    }
}

