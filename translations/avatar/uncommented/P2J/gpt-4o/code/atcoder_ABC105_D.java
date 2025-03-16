import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        long[] A = new long[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        
        long[] cumRemainders = new long[N + 1];
        cumRemainders[0] = 0;
        for (int i = 1; i <= N; i++) {
            cumRemainders[i] = (cumRemainders[i - 1] + A[i - 1]) % M;
        }
        
        Map<Long, Long> remainderCounts = new HashMap<>();
        for (long remainder : cumRemainders) {
            remainderCounts.put(remainder, remainderCounts.getOrDefault(remainder, 0L) + 1);
        }
        
        long combinations = 0;
        for (long count : remainderCounts.values()) {
            combinations += count * (count - 1) / 2;
        }
        
        System.out.println(combinations);
    }
}
//<END-OF-CODE>
