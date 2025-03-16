
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    //Scanner sc = new Scanner(System.in);
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        //int a = sc.nextInt();
        //int b = sc.nextInt();
        //int c = sc.nextInt();
        //int k = sc.nextInt();
        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());

        List<Integer> patterns = duplicatePatterns(new int[]{0, 1, 2, 3}, k);

        for (int[] P : patterns) {
            int r = a, g = b, bb = c;
            for (int i = 0; i < P.length; i++) {
                if (P[i] == 0) {
                    continue;
                } else if (P[i] == 1) {
                    r *= 2;
                } else if (P[i] == 2) {
                    g *= 2;
                } else if (P[i] == 3) {
                    bb *= 2;
                }
            }

            if (g > r && bb > g) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }

    private static List<int[]> duplicatePatterns(int[] elems, int k) {
        return duplicatePatternsRec(new int[0], elems, k);
    }

    private static List<int[]> duplicatePatternsRec(int[] pattern, int[] elems, int k) {
        if (pattern.length == k) {
            return new ArrayList<int[]>() {{
                add(pattern);
            }};
        }

        List<int[]> res = new ArrayList<>();
        for (int e : elems) {
            int[] newPattern = new int[pattern.length + 1];
            System.arraycopy(pattern, 0, newPattern, 0, pattern.length);
            newPattern[pattern.length] = e;

            res.addAll(duplicatePatternsRec(newPattern, elems, k));
        }

        return res;
    }

    //