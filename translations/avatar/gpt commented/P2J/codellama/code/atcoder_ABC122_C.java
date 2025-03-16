import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        String s = sc.next();
        int[][] problems = new int[q][2];
        for (int i = 0; i < q; i++) {
            problems[i][0] = sc.nextInt();
            problems[i][1] = sc.nextInt();
        }
        int[] cumsum = new int[n];
        cumsum[0] = 0;
        for (int i = 1; i < n; i++) {
            if (s.substring(i - 1, i + 1).equals("AC")) {
                cumsum[i] = cumsum[i - 1] + 1;
            } else {
                cumsum[i] = cumsum[i - 1];
            }
        }
        for (int i = 0; i < q; i++) {
            System.out.println(cumsum[problems[i][1] - 1] - cumsum[problems[i][0] - 1]);
        }
    }
}

