
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int q = sc.nextInt();

        String s = sc.next();

        List<List<Integer>> problems = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            List<Integer> problem = new ArrayList<>();
            problem.add(sc.nextInt());
            problem.add(sc.nextInt());
            problems.add(problem);
        }

        int[] cumsum = new int[n + 1];
        cumsum[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (s.charAt(i - 1) == 'A' && s.charAt(i) == 'C') {
                cumsum[i] = cumsum[i - 1] + 1;
            } else {
                cumsum[i] = cumsum[i - 1];
            }
        }

        for (List<Integer> problem : problems) {
            System.out.println(cumsum[problem.get(1)] - cumsum[problem.get(0) - 1]);
        }
    }
}

