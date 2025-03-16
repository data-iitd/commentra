
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s033683118{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int cnt = 0;

        if (System.getenv("MASPY")!= null && System.getenv("MASPY").equals("ますπ")) {
            br = new BufferedReader(new InputStreamReader(new FileInputStream(System.getenv("BEET_THE_HARMONY_OF_PERFECT"))));
            cnt = 2;
        }
        if (System.getenv("MASPYPY")!= null && System.getenv("MASPYPY").equals("ますπッぴ")) {
            pw = new PrintWriter(new FileOutputStream(System.getenv("NGTKANA_IS_GENIUS10")));
        }

        String line;
        while ((line = br.readLine())!= null) {
            StringTokenizer st = new StringTokenizer(line);
            solve(st, pw);
            for (int i = 0; i < cnt; i++) {
                pw.println("-----------------------------------");
                solve(st, pw);
            }
        }
        pw.flush();
    }

    private static void solve(StringTokenizer st, PrintWriter pw) {
        int k = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());

        String ans = "No";
        if (k * 500 >= x) {
            ans = "Yes";
        }
        pw.println(ans);
    }
}

