import java.io.*;
import java.util.*;

public class Main {
    static class Scanner {
        private BufferedReader br;
        private StringTokenizer st;

        public Scanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        public Scanner(String path) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(path));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

    static class Writer {
        private BufferedWriter bw;

        public Writer(OutputStream os) {
            bw = new BufferedWriter(new OutputStreamWriter(os));
        }

        public Writer(String path) throws IOException {
            bw = new BufferedWriter(new FileWriter(path));
        }

        public void write(String str) throws IOException {
            bw.write(str);
        }

        public void flush() throws IOException {
            bw.flush();
        }
    }

    static class MP {
        private String s;
        private int[] table;

        public void init(String s) {
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

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        Writer writer = new Writer(System.out);

        String s = scanner.next();
        String t = scanner.next();

        int ns = s.length();
        int nt = t.length();
        String[] ss = new String[((nt - 1) / ns) + 1];

        Arrays.fill(ss, s);

        StringBuilder sss = new StringBuilder();
        for (int i = 0; i < ss.length; i++) {
            sss.append(ss[i]);
        }
        sss.append(ss[0]);

        boolean[] ok = new boolean[ns];

        int[] uni = new int[ns];
        MP mp = new MP();
        mp.init(t);
        int m = 0;
        for (int i = 0; i < ns; i++) {
            uni[i] = i;
        }
        boolean o;
        for (int i = 0; i < ns; i++) {
            o = true;
            for (m = 0; m < nt; m++) {
                if (t.charAt(m) != sss.charAt(i + m)) {
                    o = false;
                    break;
                }
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
                writer.write("-1\n");
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

        writer.write(ans + "\n");
        writer.flush();
    }

    public static int root(int i, int[] uni) {
        if (i == uni[i]) {
            return i;
        }

        uni[i] = root(uni[i], uni);
        return uni[i];
    }
}
