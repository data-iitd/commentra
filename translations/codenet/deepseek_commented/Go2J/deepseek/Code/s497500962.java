import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int R = Integer.parseInt(st.nextToken());
        int G = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int ans = 0;
        // Iterate over all possible values of x and y
        for (int x = 0; x <= N; x++) {
            for (int y = 0; y <= N; y++) {
                // Calculate the remaining value after subtracting x*R and y*G
                int tmp = N - R*x - G*y;
                // Check if the remaining value is non-negative and a multiple of B
                if (tmp >= 0 && tmp % B == 0) {
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }
}
