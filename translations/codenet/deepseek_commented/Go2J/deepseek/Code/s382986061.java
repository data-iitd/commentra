import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the values of N and K
        int K = scanner.nextInt();
        HashMap<Integer, Integer> as = new HashMap<>(); // Create a map to keep track of the occurrences of each element
        for (int i = 1; i <= N; i++) {
            as.put(i, 0); // Initialize all elements to zero in the map
        }
        for (int i = 0; i < K; i++) {
            int d = scanner.nextInt(); // Read the number of elements chosen on the i-th day
            for (int j = 0; j < d; j++) {
                int a = scanner.nextInt(); // Read the elements chosen on the i-th day
                as.put(a, as.get(a) + 1); // Increment the count of the chosen element in the map
            }
        }
        int ans = 0; // Initialize the answer variable to count unchosen elements
        for (int value : as.values()) {
            if (value == 0) {
                ans++; // Increment the answer if an element was not chosen
            }
        }
        System.out.println(ans); // Print the number of unchosen elements
    }
}
