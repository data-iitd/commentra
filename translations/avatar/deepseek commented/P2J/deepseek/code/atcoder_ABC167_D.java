import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the values of N and K from input
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        // Read the list L of integers from input
        int[] L = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            L[i] = scanner.nextInt();
        }

        // Insert -1 at the beginning of the list L
        L[0] = -1;

        // Initialize the path list with the first element 1
        List<Integer> path = new ArrayList<>();
        path.add(1);

        // Initialize index tracker to 0
        int ind = 0;

        // Initialize count to 0
        int count = 0;

        // Initialize current position to 1
        int x = 1;

        // Initialize loop start index to -1
        int t = -1;

        // Initialize flag to indicate loop detection
        boolean flag = false;

        // Initialize a HashMap to keep track of indices of elements in path
        Map<Integer, Integer> hash = new HashMap<>();

        // Main loop to traverse the path
        for (int i = 0; i <= N; i++) {
            // Get the next element in the path
            int ne = L[x];

            // Check if the next element is already in the hash
            if (hash.containsKey(ne)) {
                // Loop detected, set flag and record the start index
                flag = true;
                t = hash.get(ne);
                break;
            }

            // Append the next element to the path and update index
            path.add(ne);
            ind++;

            // Update the hash with the current index
            hash.put(ne, ind);

            // Move to the next element
            x = ne;
        }

        // Check if a loop is detected
        if (flag) {
            // Create a loop slice from the detected start index to the end
            List<Integer> loop = path.subList(t, path.size());

            // If K is within the bounds of the path length, print the K-th element
            if (K < path.size()) {
                System.out.println(path.get(K));
            } else {
                // Adjust K for the loop length
                K = K - path.size();
                K = K % loop.size();
                // Print the K-th element of the loop
                System.out.println(loop.get(K));
            }
        } else {
            // If no loop, print the (K-1)-th element of the path
            System.out.println(path.get(K - 1));
        }
    }
}
