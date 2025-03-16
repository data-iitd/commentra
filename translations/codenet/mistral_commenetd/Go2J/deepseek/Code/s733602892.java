import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        
        int[] As = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] Fs = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        
        Arrays.sort(As);
        Arrays.sort(Fs);
        Arrays.reverse(Fs);
        
        long ok = Long.MAX_VALUE;
        long ng = -1;
        
        while (ok - ng > 1) {
            long mid = (ok + ng) / 2;
            
            long k = K;
            boolean isOK = true;
            
            for (int i = 0; i < N; i++) {
                if (As[i] * Fs[i] > mid) {
                    k -= As[i] - mid / Fs[i];
                }
                if (k < 0) {
                    isOK = false;
                    break;
                }
            }
            
            if (isOK) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        
        System.out.println(ok);
    }
}
