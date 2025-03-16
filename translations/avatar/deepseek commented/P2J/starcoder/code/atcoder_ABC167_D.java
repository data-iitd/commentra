
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the values of N and K from input
        int N = sc.nextInt();
        int K = sc.nextInt();

        // Read the list L of integers from input
        int[] L = new int[N + 1];
        for (int i = 0; i < N; i++) {
            L[i] = sc.nextInt();
        }

        // Insert -1 at the beginning of the list L
        L[N] = -1;

        // Initialize the path list with the first element 1
        List<Integer> path = new ArrayList<Integer>();
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
        HashMap<Integer, Integer> Hash = new HashMap<Integer, Integer>();

        // Main loop to traverse the path
        for (int i = 0; i < N + 1; i++) {
            // Get the next element in the path
            int ne = L[x];

            // Check if the next element is already in the Hash
            if (Hash.containsKey(ne)) {
                // Loop detected, set flag and record the start index
                flag = true;
                t = Hash.get(ne);
                break;
            }

            // Append the next element to the path and update index
            path.add(ne);
            ind += 1;

            // Update the Hash with the current index
            Hash.put(ne, ind);

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

