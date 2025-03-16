import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 1000000000 + 7;
    static final int ALPHABET_NUM = 26;
    static final long INF_INT64 = Long.MAX_VALUE;
    static final int INF_INT32 = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(br.readLine());

        List<List<Integer>> patterns = duplicatePatterns(new int[]{0, 1, 2, 3}, k);

        for (List<Integer> P : patterns) {
            int r = a, g = b, bl = c;
            for (int i = 0; i < P.size(); i++) {
                if (P.get(i) == 0) {
                    continue;
                } else if (P.get(i) == 1) {
                    r *= 2;
                } else if (P.get(i) == 2) {
                    g *= 2;
                } else if (P.get(i) == 3) {
                    bl *= 2;
                }
            }

            if (g > r && bl > g) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }

    // DuplicatePatterns returns all patterns of n^k of elems.
    static List<List<Integer>> duplicatePatterns(int[] elems, int k) {
        return dupliRec(new ArrayList<>(), elems, k);
    }

    // DFS function for DuplicatePatterns.
    static List<List<Integer>> dupliRec(List<Integer> pattern, int[] elems, int k) {
        if (pattern.size() == k) {
            List<List<Integer>> res = new ArrayList<>();
            res.add(new ArrayList<>(pattern));
            return res;
        }

        List<List<Integer>> res = new ArrayList<>();
        for (int e : elems) {
            List<Integer> newPattern = new ArrayList<>(pattern);
            newPattern.add(e);
            res.addAll(dupliRec(newPattern, elems, k));
        }

        return res;
    }
}

/* <END-OF-CODE> */
