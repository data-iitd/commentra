import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read input values for N and K
        int N = sc.nextInt();
        int K = sc.nextInt();

        // Initialize an associative array (map) named as to store the frequency of each number
        Map<Integer, Integer> as = new HashMap<Integer, Integer>();

        // Initialize all elements of the map with zero frequency
        for (int i = 1; i <= N; i++) {
            as.put(i, 0);
        }

        // Read K queries and process them
        for (int i = 0; i < K; i++) {
            // Read the length of the query
            int d = sc.nextInt();

            // Read the numbers in the query and increment their frequency in the map
            for (int j = 0; j < d; j++) {
                int a = sc.nextInt();
                as.put(a, as.get(a) + 1);
            }
        }

        // Initialize a variable named ans to store the answer
        int ans = 0;

        // Iterate through the map and check if the frequency of any number is zero
        // If yes, increment the value of ans
        for (int v : as.values()) {
            if (v == 0) {
                ans++;
            }
        }

        // Print the final answer
        System.out.println(ans);
    }
}

