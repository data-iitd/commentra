
import java.util.Scanner;

public class atcoder_ABC122_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        String s = scanner.next();
        int[][] problems = new int[q][2];
        for (int i = 0; i < q; i++) {
            problems[i][0] = scanner.nextInt();
            problems[i][1] = scanner.nextInt();
        }
        int[] cumsum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            cumsum[i] = cumsum[i - 1] + (s.substring(i - 1, i + 1).equals("AC")? 1 : 0);
        }
        for (int i = 0; i < q; i++) {
            System.out.println(cumsum[problems[i][1]] - cumsum[problems[i][0] - 1]);
        }
    }
}
