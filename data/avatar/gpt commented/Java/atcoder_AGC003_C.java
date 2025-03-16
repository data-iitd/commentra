import java.util.*; 

public class Main {
    // Define a constant for the maximum number of elements
    final static int NUM = (int) (1e5 + 2); 

    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements
        int N = sc.nextInt(); 
        
        // Initialize a HashMap to store the index of each number
        HashMap<Integer, Integer> map = new HashMap<>(); 
        
        // Initialize a PriorityQueue to store the numbers in sorted order
        PriorityQueue<Integer> nums = new PriorityQueue<>(); 
        
        // Read N numbers from input
        for (int i = 0; i < N; i++) {
            int tmp = sc.nextInt(); // Read the next number
            nums.add(tmp); // Add the number to the priority queue
            map.put(tmp, i); // Store the index of the number in the HashMap
        }
        
        // Initialize variables to track the binary state and the difference count
        int bin = 0; 
        int diff = 0; 
        
        // Process the numbers in sorted order
        while (!nums.isEmpty()) {
            int num = nums.poll(); // Retrieve and remove the smallest number
            int idx = map.get(num); // Get the original index of the number
            
            // Check if the parity of the current index and the binary state differ
            if ((bin % 2) != (idx % 2)) {
                diff++; // Increment the difference count if they differ
            }
            
            // Update the binary state
            bin++; 
            bin %= 2; // Toggle between 0 and 1
        }
        
        // Calculate the final answer as half of the difference count
        int ans = (diff / 2); 
        
        // Output the result
        System.out.println(ans); 
    }
}
