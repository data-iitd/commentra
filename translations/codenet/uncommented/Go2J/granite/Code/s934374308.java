
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

        int[] s = new int[N];
        int[] r = new int[N];
        int[] p = new int[N];
        for (int i = 0; i < N; i++) {
            s[i] = 1;
            r[i] = 1;
            p[i] = 1;
        }

        for (int i = 0; i < T.length(); i++) {
            char c = T.charAt(i);
            if (i >= K) {
                if (c == T.charAt(i - K)) {
                    switch (c) {
                        case's':
                            if (s[(i % K)] == 1) {
                                s[(i % K)] = 0;
                                continue;
                            } else {
                                s[(i % K)] = 1;
                            }
                            break;
                        case 'r':
                            if (r[(i % K)] == 1) {
                                r[(i % K)] = 0;
                                continue;
                            } else {
                                r[(i % K)] = 1;
                            }
                            break;
                        case 'p':
                            if (p[(i % K)] == 1) {
                                p[(i % K)] = 0;
                                continue;
                            } else {
                                p[(i % K)] = 1;
                            }
                            break;
                    }
                } else {
                    switch (c) {
                        case's':
                            s[(i % K)] = 1;
                            break;
                        case 'r':
                            r[(i % K)] = 1;
                            break;
                        case 'p':
                            p[(i % K)] = 1;
                            break;
                    }
                }
            }
            switch (c) {
                case's':
                    dict[0]++;
                    break;
                case 'r':
                    dict[1]++;
                    break;
                case 'p':
                    dict[2]++;
                    break;
            }
        }

        int res = dict[0] * p[0] + dict[1] * s[0] + dict[2] * r[0];
        System.out.println(res);
    }
}
