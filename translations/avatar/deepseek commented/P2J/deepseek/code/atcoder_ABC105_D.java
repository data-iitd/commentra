import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of N and M from the standard input
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        
        // Read the array A from the standard input
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        
        // Calculate the cumulative remainders of the array A modulo M
        // Include a 0 at the beginning to handle the case when the cumulative sum starts from 0
        long[] cumRemainders = new long[N + 1];
        cumRemainders[0] = 0;
        for (int i = 0; i < N; i++) {
            cumRemainders[i + 1] = (cumRemainders[i] + A[i]) % M;
        }
        
        // Count the occurrences of each remainder
        Map<Long, Integer> remainderCounts = new HashMap<>();
        for (long remainder : cumRemainders) {
            remainderCounts.put(remainder, remainderCounts.getOrDefault(remainder, 0) + 1);
        }
        
        // Initialize the number of combinations
        long combinations = 0;
        
        // Calculate the number of combinations where the difference between two remainders is a multiple of M
        for (int count : remainderCounts.values()) {
            combinations += (long) count * (count - 1) / 2;
        }
        
        // Print the number of combinations
        System.out.println(combinations);
    }
}
