import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        int[] s = new int[A + 2];
        s[0] = Integer.MIN_VALUE;
        s[A + 1] = Integer.MAX_VALUE;
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= A; i++) {
            s[i] = Integer.parseInt(st.nextToken());
        }

        int[] t = new int[B + 2];
        t[0] = Integer.MIN_VALUE;
        t[B + 1] = Integer.MAX_VALUE;
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= B; i++) {
            t[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int b = binarySearch(s, x);
            int d = binarySearch(t, x);
            int res = Integer.MAX_VALUE;
            for (int S : new int[]{s[b - 1], s[b]}) {
                for (int T : new int[]{t[d - 1], t[d]}) {
                    int d1 = Math.abs(S - x) + Math.abs(T - S);
                    int d2 = Math.abs(T - x) + Math.abs(S - T);
                    res = Math.min(res, Math.min(d1, d2));
                }
            }

            System.out.println(res);
        }
    }

    private static int binarySearch(int[] arr, int key) {
        int low = 0;
        int high = arr.length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
}
