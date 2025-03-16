
import java.util.*;
import java.io.*;

class s325320702 {
    public static void main(String[] args) throws Exception {
        // Read input values for l, r, and d
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long l = Long.parseLong(br.readLine());
        long r = Long.parseLong(br.readLine());
        long d = Long.parseLong(br.readLine());

        // Count the multiples of d in the range [l, r]
        long ans = 0;
        for (long i = l; i <= r; i++) {
            if (i % d == 0) ans++;
        }

        // Output the result
        System.out.println(ans);
    }
}

