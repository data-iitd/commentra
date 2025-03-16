import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        String s = sc.next();
        int[] problems = new int[q][2];
        for (int i = 0; i < q; i++) {
            problems[i] = new int[]{sc.nextInt(), sc.nextInt()};
        }
        int[] cumsum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            cumsum[i] = cumsum[i - 1] + (s.charAt(i - 1) == 'A' && s.charAt(i) == 'C'? 1 : 0);
        }
        for (int[] problem : problems) {
            System.out.println(cumsum[problem[1] - 1] - cumsum[problem[0] - 1]);
        }
    }
}
