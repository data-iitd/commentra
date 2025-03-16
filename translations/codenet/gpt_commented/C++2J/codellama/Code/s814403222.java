import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        while (sc.hasNextInt()) {
            n = sc.nextInt();
            if (n == 0) {
                break;
            }
            int[][] scores = new int[n][2];
            for (int i = 0; i < n; i++) {
                scores[i][0] = 0;
                scores[i][1] = sc.nextInt();
                int m = sc.nextInt();
                for (int j = 0; j < m; j++) {
                    int a = sc.nextInt();
                    scores[i][0] += n - scores[a][1];
                    scores[a][1]--;
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (scores[i][0] < scores[j][0]) {
                        int[] temp = scores[i];
                        scores[i] = scores[j];
                        scores[j] = temp;
                    }
                }
            }
            System.out.println(scores[0][0] + " " + scores[0][1]);
        }
    }
}

