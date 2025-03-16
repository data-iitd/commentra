import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            solve(br);
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        String x = br.readLine();
        List<Integer> s = new ArrayList<>();
        for (char c : x.toCharArray()) {
            if (c == 'O') {
                s.add(0);
            } else {
                s.add(1);
            }
        }

        List<int[]> tot = new ArrayList<>();
        for (int i = 1; i <= 12; i++) {
            if (12 % i == 0) {
                if (help(i, 12 / i, s)) {
                    tot.add(new int[]{12 / i, i});
                }
            }
        }

        System.out.print(tot.size() + " ");
        Collections.sort(tot, Comparator.comparingInt(a -> a[0]));
        for (int[] pair : tot) {
            System.out.print(pair[0] + "x" + pair[1] + " ");
        }
        System.out.println();
    }

    private static boolean help(int a, int b, List<Integer> l) {
        List<List<Integer>> tot = new ArrayList<>();
        for (int i = 0; i < b; i++) {
            tot.add(l.subList(i * a, i * a + a));
        }
        for (int j = 0; j < a; j++) {
            int sum = 0;
            for (int i = 0; i < b; i++) {
                sum += tot.get(i).get(j);
            }
            if (sum == b) {
                return true;
            }
        }
        return false;
    }
}
