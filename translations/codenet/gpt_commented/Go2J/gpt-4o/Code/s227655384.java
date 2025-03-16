import java.io.*;
import java.util.*;

public class Main {
    // Method to read a specified number of long lines from standard input
    public static List<String> readLongLines(int times) throws IOException {
        List<String> result = new ArrayList<>(times); // Create a list to hold the lines read
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); // Create a buffered reader for standard input

        // Loop to read the specified number of lines
        for (int i = 0; i < times; i++) {
            StringBuilder buffer = new StringBuilder(); // Buffer to accumulate line data
            String line;
            while ((line = reader.readLine()) != null) { // Read a line from input
                buffer.append(line); // Write the read line to the accumulator
                if (line.endsWith("\n")) { // Check if the line is complete
                    break; // Break out of the inner loop to read the next line
                }
            }
            result.add(buffer.toString()); // Store the complete line in the result
        }
        return result; // Return the lines read
    }

    // Method to print a list of integers to the console
    public static void printList(List<Integer> list) {
        StringBuilder output = new StringBuilder(); // Create a StringBuilder for output
        for (int i = 0; i < list.size(); i++) {
            if (i > 0) {
                output.append(" "); // Add a leading space for subsequent elements
            }
            output.append(list.get(i)); // Append the integer to the output
        }
        System.out.println(output.toString()); // Print the output
    }

    // Main method where the program execution begins
    public static void main(String[] args) throws IOException {
        Map<Integer, Boolean> m = new HashMap<>(); // Create a map to track unique integers
        List<String> lines = readLongLines(4); // Read 4 lines from input
        String[] a = lines.get(1).split(" "); // Split the second line into individual strings

        // Convert strings to integers and store them in the map
        for (String s : a) {
            int n = Integer.parseInt(s); // Convert string to integer
            m.put(n, true); // Add the integer to the map
        }

        List<Integer> result = new ArrayList<>(); // List to hold the result integers
        String[] b = lines.get(3).split(" "); // Split the fourth line into individual strings

        // Process the integers from the fourth line
        for (String s : b) {
            int n = Integer.parseInt(s); // Convert string to integer
            if (m.containsKey(n)) { // Check if the integer exists in the map
                m.remove(n); // Remove it from the map if it exists
            } else {
                m.put(n, true); // Add it to the map if it does not exist
            }
        }

        // Collect remaining integers from the map into the result list
        for (Integer k : m.keySet()) {
            result.add(k); // Append the key to the result list
        }

        // Sort the result list in ascending order
        Collections.sort(result);

        // Print the sorted result
        for (Integer j : result) {
            System.out.println(j); // Print each integer in the result
        }
    }
}
// <END-OF-CODE>
