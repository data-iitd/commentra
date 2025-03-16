import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of pairs (N) from the input
        int N = sc.nextInt();
        
        // Initialize an array to hold 2*N integers
        int[] map = new int[N * 2];
        
        // Populate the array with integers from the input
        for (int i = 0; i < N * 2; i++) {
            map[i] = sc.nextInt();
        }
        
        // Sort the array in ascending order
        Arrays.sort(map);
        
        // Initialize a variable to hold the maximum sum of pairs
        int max = 0;
        
        // Iterate through the sorted array, taking pairs of elements
        for (int i = 0; i < N * 2; i += 2) {
            // Add the minimum of each pair to the max sum
            max += Math.min(map[i], map[i + 1]);
        }
        
        // Output the maximum sum of pairs
        System.out.println(max);
    }
}
