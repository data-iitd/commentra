
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s541050824{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int N = Integer.parseInt(br.readLine());
        int[] T = new int[N];
        int[] A = new int[N];
        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            T[i] = Integer.parseInt(st.nextToken());
            A[i] = Integer.parseInt(st.nextToken());
        }
        long t = T[0], a = A[0];
        for (int i = 1; i < N; i++) {
            long r = Math.max(t / T[i], a / A[i]);
            t = T[i] * r;
            a = A[i] * r;
        }
        out.println(t + a);
        out.close();
    }
}

