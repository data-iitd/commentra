import java.io.*;
import java.util.*;

public class Main {
    // Scanner for input
    private static Scanner getScanner(InputStream inputStream) {
        return new Scanner(inputStream);
    }

    // Get next string from scanner
    private static String getNextString(Scanner scanner) {
        return scanner.next();
    }

    // Get next integer from scanner
    private static int getNextInt(Scanner scanner) {
        return Integer.parseInt(getNextString(scanner));
    }

    // Get next long from scanner
    private static long getNextLong(Scanner scanner) {
        return Long.parseLong(getNextString(scanner));
    }

    // Get next double from scanner
    private static double getNextDouble(Scanner scanner) {
        return Double.parseDouble(getNextString(scanner));
    }

    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;

        // Check for environment variables (similar to Go code)
        String maspy = System.getenv("MASPY");
        String maspyPy = System.getenv("MASPYPY");
        if ("ますピ".equals(maspy)) {
            inputStream = new FileInputStream(System.getenv("BEET_THE_HARMONY_OF_PERFECT"));
        }
        if ("ますピッピ".equals(maspyPy)) {
            outputStream = new FileOutputStream(System.getenv("NGTKANA_IS_GENIUS10"));
        }

        Scanner scanner = getScanner(inputStream);
        PrintWriter writer = new PrintWriter(outputStream);

        String s = getNextString(scanner);
        String t = getNextString(scanner);

        int ns = s.length();
        int nt = t.length();
        String[] ss = new String[(nt - 1) / ns + 1];

        Arrays.fill(ss, s);
        String sss = String.join("", ss) + String.join("", ss);

        boolean[] ok = new boolean[ns];
        int[] uni = new int[ns];
        MP mp = new MP();
        mp.init(t);
        int m = 0;

        for (int i = 0; i < ns; i++) {
            uni[i] = i;
        }

        for (int i = 0; i < ns; i++) {
            boolean o = true;
            m = 0;
            while (m < nt) {
                if (t.charAt(m) != sss.charAt(i + m)) {
                    o = false;
                    break;
                }
                m++;
            }
            ok[i] = o;
            if (o) {
                i += nt - mp.table[m];
                m = mp.table[m];
            }
            while (m >= 0 && t.charAt(m) != sss.charAt(i + m)) {
                i += m - mp.table[m];
                m = mp.table[m];
            }
            i--;
            m++;
        }

        int ans = 0;
        int r, rr;
        for (int i = 0; i < ns; i++) {
            if (!ok[i]) continue;
            if (!ok[(i + nt) % ns]) continue;
            r = root(i, uni);
            rr = root((i + nt) % ns, uni);
            if (rr == r) {
                writer.println(-1);
                writer.flush();
                return;
            }
            uni[rr] = r;
        }

        int[] counter = new int[ns];
        for (int i = 0; i < ns; i++) {
            r = root(i, uni);
            if (!ok[r]) continue;
            counter[r]++;
        }
        for (int i = 0; i < ns; i++) {
            if (ans < counter[i]) {
                ans = counter[i];
            }
        }

        writer.println(ans);
        writer.flush();
    }

    // Union-find root function
    private static int root(int i, int[] uni) {
        if (i == uni[i]) {
            return i;
        }
        uni[i] = root(uni[i], uni);
        return uni[i];
    }

    // MP class for pattern matching
    static class MP {
        String s;
        int[] table;

        void init(String s) {
            this.s = s;
            int n = s.length();
            table = new int[n + 1];
            table[0] = -1;
            int j = -1;
            for (int i = 0; i < n; i++) {
                while (j >= 0 && s.charAt(i) != s.charAt(j)) {
                    j = table[j];
                }
                j++;
                table[i + 1] = j;
            }
        }
    }
}
// <END-OF-CODE>
