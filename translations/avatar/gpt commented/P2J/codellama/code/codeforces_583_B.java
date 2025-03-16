public class Main {
    public static void main(String[] args) {
        // Read an integer input which represents the number of elements
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        // Read a line of input, split it by spaces, and convert it to a list of integers
        String[] a = scanner.nextLine().split(" ");
        int[] a_int = new int[a.length];
        for (int i = 0; i < a.length; i++) {
            a_int[i] = Integer.parseInt(a[i]);
        }
        
        // Initialize the current level and counters
        int current_level = 0;
        int counter = 0;
        int counter_turns = -1;  // Start with -1 to account for the first turn increment
        
        // Loop until all elements have been processed
        while (counter < a_int.length) {
            counter_turns += 1;  // Increment the turn counter
            
            // Iterate through the list to find elements that can be processed
            for (int i = 0; i < a_int.length; i++) {
                // Check if the current element is not marked (-1) and is less than or equal to the current counter
                if (a_int[i] != -1 && a_int[i] <= counter) {
                    counter += 1;  // Increment the counter as we can process this element
                    a_int[i] = -1;  // Mark the element as processed by setting it to -1
                }
            }
            
            // Reverse the list to prepare for the next round of processing
            for (int i = 0; i < a_int.length / 2; i++) {
                int temp = a_int[i];
                a_int[i] = a_int[a_int.length - i - 1];
                a_int[a_int.length - i - 1] = temp;
            }
        }
        
        // Print the total number of turns taken to process all elements
        System.out.println(counter_turns);
    }
}

