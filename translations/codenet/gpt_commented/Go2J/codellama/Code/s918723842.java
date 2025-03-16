
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int H = sc.nextInt();
        int W = sc.nextInt();
        int N = sc.nextInt();

        int A = Math.max(H, W);

        System.out.println((N + A - 1) / A);
    }

    static class Scanner {
        BufferedReader r;
        String[] buf = new String[1000];
        int p = 0;

        Scanner() {
            r = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            pre();
            int start = p;
            while (p < buf.length && buf[p] != ' ') {
                p++;
            }
            String result = buf[start] + (p - start == 1 ? "" : buf[start + 1] + (p - start == 2 ? "" : String.join("", buf[start + 2])));
            p++;
            return result;
        }

        String nextLine() {
            pre();
            int start = p;
            p = buf.length;
            return String.join("", buf[start]);
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int nextIntArray() {
            pre();
            int start = p;
            List<Integer> result = new ArrayList<>();
            while (p < buf.length + 1) {
                if (p == buf.length || buf[p] == ' ') {
                    result.add(Integer.parseInt(String.join("", buf[start])));
                    start = p + 1;
                }
            }
            return result.get(result.size() - 1);
        }

        int[] nextIntArrayArray() {
            pre();
            int start = p;
            List<Integer> result = new ArrayList<>();
            while (p < buf.length + 1) {
                if (p == buf.length || buf[p] == ' ') {
                    result.add(Integer.parseInt(String.join("", buf[start])));
                    start = p + 1;
                }
            }
            return result.stream().mapToInt(i -> i).toArray();
        }

        Map<Integer, Boolean> nextMap() {
            pre();
            int start = p;
            Map<Integer, Boolean> mp = new HashMap<>();
            while (p < buf.length) {
                if (buf[p] == ' ') {
                    mp.put(Integer.parseInt(String.join("", buf[start])), true);
                    start = p + 1;
                }
            }
            mp.put(Integer.parseInt(String.join("", buf[start])), true);
            return mp;
        }

        void pre() {
            if (p >= buf.length) {
                readLine();
                p = 0;
            }
        }

        void readLine() {
            buf = new BufferedReader(new InputStreamReader(System.in)).lines().toArray(String[]::new);
        }
    }
}

