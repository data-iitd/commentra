import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class EvacuationRoute {
    static final int INF = 0x5fffffff;
    static int[] a = new int[100002];
    static int[] b = new int[100002];

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        int w = Integer.parseInt(line.trim());
        line = reader.readLine();
        String[] inputs = line.trim().split(" ");
        
        int ans = 0, f = 0;
        for (int i = 1; i <= w; i++) {
            a[i] = Integer.parseInt(inputs[i - 1]);
            if (a[i] == 0) f |= 1;
            else if (a[i] < 0) f |= 2;
            else ans += a[i];
        }
        
        if (ans == 0 || (f & 1) == 0) {
            System.out.println("0");
            return;
        }
        if ((f & 2) == 0) {
            System.out.println(ans);
            return;
        }

        int close = 0;
        f = 0;
        for (int i = 1; i <= w; i++) {
            if (a[i] == 0) {
                close = INF;
                f = -1;
            } else if (a[i] < 0) {
                if (f < 0 || close - (i - f) > -a[i]) {
                    close = -a[i];
                    f = i;
                }
            } else {
                if (f < 0) {
                    b[i] = INF;
                } else {
                    int k = close - (i - f);
                    if (k < 0) k = 0;
                    b[i] = k;
                }
            }
        }

        close = 0;
        f = w;
        for (int i = w; i >= 1; i--) {
            if (a[i] == 0) {
                close = INF;
                f = -1;
            } else if (a[i] < 0) {
                if (f < 0 || close - (f - i) > -a[i]) {
                    close = -a[i];
                    f = i;
                }
            } else {
                if (f < 0) {
                    b[i] = INF;
                } else {
                    int k = close - (f - i);
                    if (k < 0) k = 0;
                    if (k > b[i]) b[i] = k;
                }
            }
        }

        ans = 0;
        for (int i = 1; i <= w; i++) {
            if (a[i] > 0) {
                if (b[i] > a[i]) ans += a[i];
                else ans += b[i];
            }
        }
        System.out.println(ans);
    }
}
// <END-OF-CODE>
