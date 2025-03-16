
import java.util.*;
import java.io.*;

class atcoder_ABC169_E {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] low = new int[n];
        int[] high = new int[n];
        for (int i = 0; i < n; i++) {
            String[] ab = br.readLine().split(" ");
            low[i] = Integer.parseInt(ab[0]);
            high[i] = Integer.parseInt(ab[1]);
        }
        Arrays.sort(low);
        Arrays.sort(high);
        if (n % 2 == 1) {
            System.out.println(high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
        } else {
            int hh = (high[n / 2 - 1] + high[n / 2]) / 2;
            int ll = (low[n / 2 - 1] + low[n / 2]) / 2;
            System.out.println(2 * (hh - ll) + 1);
        }
    }
}

Translate the above Python code to C++ and end with comment "