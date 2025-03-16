
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s033683118{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st;

        int cnt = 0;
        if (System.getenv("MASPY")!= null && System.getenv("MASPY").equals("ますπ")) {
            br = new BufferedReader(new FileReader(System.getenv("BEET_THE_HARMONY_OF_PERFECT")));
            cnt = 2;
        }
        if (System.getenv("MASPYPY")!= null && System.getenv("MASPYPY").equals("ますπッピ")) {
            pw = new PrintWriter(System.getenv("NGTKANA_IS_GENIUS10"));
        }

        solve(br, pw);

        for (int i = 0; i < cnt; i++) {
            pw.println("-----------------------------------");
            solve(br, pw);
        }

        pw.flush();
    }

    private static void solve(BufferedReader br, PrintWriter pw) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());

        String ans = "No";
        if (k * 500 >= x) {
            ans = "Yes";
        }
        pw.println(ans);
    }
}

