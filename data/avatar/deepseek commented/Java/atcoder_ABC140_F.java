import java.util.*; // Importing necessary libraries

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize Scanner object to read input
        int N = sc.nextInt(); // Read the integer N from standard input
        int size = (1 << N); // Calculate the size of the array S, which is 2^N
        int[] S = new int[size]; // Initialize an array S to store integers
        boolean[] spawned = new boolean[size]; // Initialize a boolean array to track spawned elements
        spawned[size - 1] = true; // Set the last element of spawned to true, indicating it's initially active

        // Read integers into the array S
        for (int i = 0; i < size; i++) {
            S[i] = sc.nextInt();
        }

        Arrays.sort(S); // Sort the array S
        List<Integer> active = new ArrayList<>(); // Initialize a list to keep track of active elements
        active.add(S[size - 1]); // Add the largest element from S to the active list and mark it as spawned
        spawned[size - 1] = true;

        // Iterate N times
        for (int i = 0; i < N; i++) {
            active.sort(Collections.reverseOrder()); // Sort the active list in reverse order
            List<Integer> activated = new ArrayList<>(); // Initialize a list to find new activated elements
            int next = size - 1; // Initialize next to find new activated elements

            // Find new activated elements
            for (int slime : active) {
                while (next >= 0 && (S[next] >= slime || spawned[next])) {
                    next--;
                }
                if (next < 0) {
                    System.out.println("No"); // If no new activated elements are found, print "No"
                    return;
                }
                spawned[next] = true; // Mark the found element as spawned
                activated.add(S[next]); // Add the found element to the activated list
            }
            active.addAll(activated); // Add the activated elements to the active list
        }
        System.out.println("Yes"); // If N iterations are successful, print "Yes"
    }
}
