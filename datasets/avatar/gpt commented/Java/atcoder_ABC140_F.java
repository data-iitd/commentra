import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the integer N which determines the size of the input array
        int N = sc.nextInt();
        
        // Calculate the size of the array as 2^N
        int size = (1 << N);
        
        // Initialize an array S to hold the input values
        int[] S = new int[size];
        
        // Initialize a boolean array to track which elements have been spawned
        boolean[] spawned = new boolean[size];
        
        // Mark the last element as spawned (the largest element)
        spawned[size - 1] = true;
        
        // Read N elements into the array S
        for (int i = 0; i < size; i++) {
            S[i] = sc.nextInt();
        }
        
        // Sort the array S in ascending order
        Arrays.sort(S);
        
        // Create a list to keep track of active slimes
        List<Integer> active = new ArrayList<>();
        
        // Add the largest element to the active list
        active.add(S[size - 1]);
        
        // Mark the largest element as spawned
        spawned[size - 1] = true;
        
        // Iterate N times to activate new slimes
        for (int i = 0; i < N; i++) {
            // Sort the active list in descending order
            active.sort(Collections.reverseOrder());
            
            // Create a list to keep track of newly activated slimes
            List<Integer> activated = new ArrayList<>();
            
            // Initialize the next index to the last element of S
            int next = size - 1;
            
            // Iterate through each slime in the active list
            for (int slime : active) {
                // Find the next unspawned element that is less than the current slime
                while (next >= 0 && (S[next] >= slime || spawned[next])) {
                    next--;
                }
                
                // If no valid unspawned element is found, print "No" and exit
                if (next < 0) {
                    System.out.println("No");
                    return;
                }
                
                // Mark the found element as spawned
                spawned[next] = true;
                
                // Add the newly activated slime to the activated list
                activated.add(S[next]);
            }
            
            // Add all newly activated slimes to the active list
            active.addAll(activated);
        }
        
        // If all iterations complete successfully, print "Yes"
        System.out.println("Yes");
    }
}
