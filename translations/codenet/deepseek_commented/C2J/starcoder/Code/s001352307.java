import java.util.*;

public class Knapsack {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t, i, j, W, N;
        int[][] input = new int[1024][2];
        int[][] ans = new int[1024][2];

        for(t = 0; ; t++) {
            for(i = 0; i < 1024; i++) {
                ans[i][0] = 0;
                ans[i][1] = 0;
                input[i][0] = 0;
                input[i][1] = 0;
            }

            W = in.nextInt();
            N = in.nextInt();
            if(W == 0)
                break;

            for(i = 0; i < N; i++) {
                input[i][0] = in.nextInt();
                input[i][1] = in.nextInt();
            }

            for(i = 0; i < N; i++) {
                for(j = 1023; j >= input[i][1]; j--) {
                    if(ans[j][0] < input[i][0] + ans[j - input[i][1]][0]) {
                        ans[j][0] = input[i][0] + ans[j - input[i][1]][0];
                        ans[j][1] = input[i][1] + ans[j - input[i][1]][1];
                    }
                }
            }

            for(j = 0; ans[W][0] == ans[W - j - 1][0]; j++);

            System.out.printf("Case %d:\n%d\n%d\n", t + 1, ans[W - j][0], ans[W - j][1]);
        }
    }
}
