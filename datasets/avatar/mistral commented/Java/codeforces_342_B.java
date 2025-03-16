
import java.io.BufferedReader; // BufferedReader to read input from System.in
import java.io.IOException; // Exception for I/O errors
import java.io.InputStreamReader; // InputStreamReader to read from System.in
import java.util.ArrayList; // ArrayList for storing integers
import java.util.HashMap; // HashMap for storing integers as keys and ArrayLists as values

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); // Initialize BufferedReader to read input

        String input[] = reader.readLine().split(" "); // Read the first line of input and split it into an array
        int m = Integer.parseInt(input[0]); // Read the number of methods
        int s = Integer.parseInt(input[2]); // Read the start position
        int f = Integer.parseInt(input[3]); // Read the finish position
        int maxT = -1; // Initialize maximum thread ID

        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>(); // Create a HashMap to store thread IDs and their arrival and departure times

        // Read the remaining lines of input and store the thread IDs and their arrival and departure times in the HashMap
        while (m > 0) {
            String mth[] = reader.readLine().split(" "); // Read a line of input and split it into an array
            int k = Integer.parseInt(mth[0]); // Read the thread ID
            map.put(k, new ArrayList<>()); // Create a new ArrayList for the given thread ID
            map.get(k).add(Integer.parseInt(mth[1])); // Add the arrival time to the ArrayList
            map.get(k).add(Integer.parseInt(mth[2])); // Add the departure time to the ArrayList
            maxT = Math.max(maxT, k); // Update the maximum thread ID
            m--; // Decrement the number of methods to be read
        }

        StringBuilder actions = new StringBuilder(); // Initialize a StringBuilder to store the output
        final char M = (s < f) ? 'R' : 'L'; // Determine the direction of the simulation based on the start and finish positions
        int d = (s < f) ? 1 : -1; // Determine the direction of the simulation as 1 for right and -1 for left
        int cur = s; // Initialize the current position
        int a = -1; // Initialize variables for storing the arrival and departure times of the current thread
        int b = -1;

        // Simulate the execution of threads and generate the output
        for (int t = 1; t <= maxT; t++) {
            if (map.containsKey(t)) { // Check if there is a thread with the given ID
                a = map.get(t).get(0); // Get the arrival time of the thread
                b = map.get(t).get(1); // Get the departure time of the thread

                if (map.containsKey(t) && (cur >= a && cur <= b || cur + d >= a && cur + d <= b)) { // Check if the current position is within the execution time of the thread
                    actions.append('X'); // Append an 'X' to the output if the current position is within the execution time of the thread
                } else {
                    actions.append(M); // Append the direction character to the output if the current position is not within the execution time of the thread
                    cur += d; // Move the current position in the direction of the simulation
                }

                if (cur == f) { // Break the loop if the finish position is reached
                    break;
                }
            } else {
                actions.append(M); // Append the direction character to the output if there is no thread at the current position
                cur += d; // Move the current position in the direction of the simulation
            }
        }

        // Print the output to the console
        while (cur != f) {
            actions.append(M);
            cur += d;
        }
        System.out.println(actions);
    }
}