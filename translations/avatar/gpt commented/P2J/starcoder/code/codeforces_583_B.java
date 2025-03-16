public class Main {
    public static void main(String[] args) {
        // Read an integer input which represents the number of elements
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        // Read a line of input, split it by spaces, and convert it to a list of integers
        String[] a = sc.nextLine().split(" ");
        int[] a_arr = new int[n];
        for (int i = 0; i < n; i++) {
            a_arr[i] = Integer.parseInt(a[i]);
        }
        
        // Initialize the current level and counters
        int current_level = 0;
        int counter = 0;
        int counter_turns = -1;  // Start with -1 to account for the first turn increment
        
        // Loop until all elements have been processed
        while (counter < n) {
            counter_turns += 1;  // Increment the turn counter
            
            // Iterate through the list to find elements that can be processed
            for (int i = 0; i < n; i++) {
                // Check if the current element is not marked (-1) and is less than or equal to the current counter
                if (a_arr[i]!= -1 && a_arr[i] <= counter) {
                    counter += 1;  // Increment the counter as we can process this element
                    a_arr[i] = -1;  // Mark the element as processed by setting it to -1
                }
            }
            
            // Reverse the list to prepare for the next round of processing
            reverse(a_arr, 0, n - 1);
        }
        
        // Print the total number of turns taken to process all elements
        System.out.println(counter_turns);
    }
    
    public static void reverse(int[] a, int start, int end) {
        while (start < end) {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            start++;
            end--;
        }
    }
}

