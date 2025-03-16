import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        // Read input number of rows and columns
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        // Initialize array 'A' with given dimensions
        long[] A = new long[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        
        // Calculate cumulative remainders
        long[] cumRemainders = new long[N + 1];
        for (int i = 1; i <= N; i++) {
            cumRemainders[i] = (cumRemainders[i - 1] + A[i - 1]) % M;
        }
        
        // Count the occurrences of each cumulative remainder
        Map<Long, Long> remainderCounts = new HashMap<>();
        for (long remainder : cumRemainders) {
            remainderCounts.put(remainder, remainderCounts.getOrDefault(remainder, 0L) + 1);
        }
        
        // Calculate the number of combinations of elements having the same remainder
        long combinations = 0;
        for (long count : remainderCounts.values()) {
            combinations += count * (count - 1) / 2;
        }
        
        // Print the result
        System.out.println(combinations);
    }
}
// <END-OF-CODE>
