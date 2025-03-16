import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        // Read the values of N and M
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        // Read the array A
        long[] A = new long[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        
        // Calculate cumulative remainders of the array A when divided by M
        long[] cumRemainders = new long[N + 1];
        cumRemainders[0] = 0; // Start with 0 to handle the case of subarrays starting from index 0
        
        for (int i = 1; i <= N; i++) {
            cumRemainders[i] = (cumRemainders[i - 1] + A[i - 1]) % M;
        }
        
        // Count the occurrences of each remainder using a HashMap
        Map<Long, Long> remainderCounts = new HashMap<>();
        for (long remainder : cumRemainders) {
            remainderCounts.put(remainder, remainderCounts.getOrDefault(remainder, 0L) + 1);
        }
        
        // Initialize a variable to count the number of valid combinations
        long combinations = 0;
        
        // Calculate the number of combinations of indices that have the same remainder
        for (long count : remainderCounts.values()) {
            combinations += count * (count - 1) / 2; // Combinations of 2 from count
        }
        
        // Output the total number of combinations found
        System.out.println(combinations);
    }
}
// <END-OF-CODE>
