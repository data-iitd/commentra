
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int magic = 1000000007;

    static int N;
    static int[] p;

    static int find(int n) {
        for (int i = 0; i < N; i++) {
            if (n == p[i]) {
                return 0;
            }
        }
        return 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int X = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        p = new int[N];
        for (int i = 0; i < N; i++) {
            p[i] = Integer.parseInt(br.readLine());
        }

        for (int i = 0; i <= 100; i++) {
            if (find(X - i) == 1) {
                System.out.println(X - i);
                return;
            }
            if (find(X + i) == 1) {
                System.out.println(X + i);
                return;
            }
        }

        // OUTPUT GENERATION PART
        int ans = 0;
        System.out.println(ans);

        // If ans > 0, print "Yes" and exit; otherwise, print "No"
        if (ans > 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

