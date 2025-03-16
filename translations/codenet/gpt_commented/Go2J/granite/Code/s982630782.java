
import java.util.*;

public class s982630782{
    public static void main(String[] args) {
        // Initialize a map to count occurrences of integers
        Map<Integer, Integer> m = new HashMap<>();

        // Read the number of initial integers (N) and the number of operations (M)
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        // Read N integers and count their occurrences in the map
        for (int i = 0; i < N; i++) {
            int num = scanner.nextInt();
            m.put(num, m.getOrDefault(num, 0) + 1);
        }

        // Process M operations, where each operation adds B occurrences of integer C
        for (int i = 0; i < M; i++) {
            int B = scanner.nextInt();
            int C = scanner.nextInt();
            m.put(C, m.getOrDefault(C, 0) + B);
        }

        // Create a list to hold the unique integers from the map
        List<Integer> ints = new ArrayList<>(m.keySet());

        // Sort the integers in descending order
        Collections.sort(ints, Collections.reverseOrder());

        // Initialize variables to keep track of remaining integers and the total sum
        int rest = N;
        int sum = 0;

        // Calculate the maximum sum based on the sorted integers
        for (int i : ints) {
            int num = m.get(i);
            // If the number of occurrences is greater than or equal to the remaining count
            if (num >= rest) {
                sum += rest * i; // Add the product of remaining count and the integer
                break; // Exit the loop as we have used all remaining integers
            }
            sum += num * i; // Add the product of occurrences and the integer to the sum
            rest -= num; // Decrease the remaining count by the number of occurrences
        }

        // Output the final calculated sum
        System.out.println(sum);
    }
}

// Translate the above Java code to C++ and end with comment "