import java.util.Scanner;

public class Knapsack {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int W, N;
        int[][] input = new int[1024][2];
        int[][] ans = new int[1024][2];
        int t = 0;

        while (true) {
            // Initialize arrays
            for (int i = 0; i < 1024; i++) {
                ans[i][0] = 0;
                ans[i][1] = 0;
                input[i][0] = 0;
                input[i][1] = 0;
            }

            W = scanner.nextInt();
            N = scanner.nextInt();
            if (W == 0) {
                break;
            }

            for (int i = 0; i < N; i++) {
                String[] parts = scanner.next().split(",");
                input[i][0] = Integer.parseInt(parts[0]);
                input[i][1] = Integer.parseInt(parts[1]);
            }

            for (int i = 0; i < N; i++) {
                for (int j = 1023; j >= input[i][1]; j--) {
                    if (ans[j][0] < input[i][0] + ans[j - input[i][1]][0]) {
                        ans[j][0] = input[i][0] + ans[j - input[i][1]][0];
                        ans[j][1] = input[i][1] + ans[j - input[i][1]][1];
                    }
                }
            }

            int j;
            for (j = 0; ans[W][0] == ans[W - j - 1][0]; j++);

            System.out.printf("Case %d:\n%d\n%d\n", t + 1, ans[W - j][0], ans[W - j][1]);
            t++;
        }

        scanner.close();
    }
}
// <END-OF-CODE>
