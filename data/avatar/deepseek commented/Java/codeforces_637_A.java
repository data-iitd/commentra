import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Initialize Scanner to read input
        PrintWriter pw = new PrintWriter(System.out); // Initialize PrintWriter to write output

        int n = in.nextInt(); // Read the number of elements
        int ara[] = new int[n]; // Initialize array to store elements
        Map<Integer, Integer> map = new HashMap<>(); // HashMap to count occurrences of each element

        // Populate the array and the map with element counts
        for (int i = 0; i < n; i++) {
            int v = in.nextInt();
            ara[i] = v;
            if (!map.containsKey(v)) {
                map.put(v, 1); // Initialize count for new element
            } else {
                map.put(v, map.get(v) + 1); // Increment count for existing element
            }
        }

        int max = 0; // Initialize max to track the highest frequency
        // Find the maximum frequency in the map
        for (Integer i : map.values()) {
            max = Math.max(max, i);
        }

        Map<Integer, Integer> mm = new HashMap<>(); // HashMap to track occurrences as elements appear
        // Find the most frequent element
        for (int i = 0; i < n; i++) {
            if (!mm.containsKey(ara[i])) {
                mm.put(ara[i], 1); // Initialize count for new element
                if (mm.get(ara[i]) == max) {
                    pw.println(ara[i]); // Print the most frequent element
                    break; // Exit the loop after finding the most frequent element
                }
            } else {
                mm.put(ara[i], mm.get(ara[i]) + 1); // Increment count for existing element
                if (mm.get(ara[i]) == max) {
                    pw.println(ara[i]); // Print the most frequent element
                    break; // Exit the loop after finding the most frequent element
                }
            }
        }

        pw.close(); // Close PrintWriter to flush output
    }

    static void debug(Object... obj) {
        System.err.println(Arrays.deepToString(obj)); // Print debugging information
    }
}
