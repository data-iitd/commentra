import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        // Create a set to store unique elements.
        Set<Integer> set = new HashSet<>();
        String[] lines = new String[4];

        // Read the first three lines.
        for (int i = 0; i < 4; i++) {
            lines[i] = reader.readLine();
        }

        // Split the second line into individual elements and add them to the set.
        String[] a = lines[1].split(" ");
        for (String s : a) {
            int n = Integer.parseInt(s);
            set.add(n);
        }

        // Process the fourth line to toggle the presence of elements in the set.
        String[] b = lines[3].split(" ");
        for (String s : b) {
            int n = Integer.parseInt(s);
            if (set.contains(n)) {
                set.remove(n);
            } else {
                set.add(n);
            }
        }

        // Extract the unique elements from the set and sort them.
        List<Integer> result = new ArrayList<>(set);
        Collections.sort(result);

        // Print the sorted list of unique elements.
        for (int num : result) {
            writer.write(num + "\n");
        }

        // Close the writer.
        writer.flush();
    }
}

