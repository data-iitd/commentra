
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class s227655384{
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        List<String> lines = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            lines.add(reader.readLine());
        }

        // Create a map to store unique elements.
        List<Integer> m = new ArrayList<>();

        // Split the second line into individual elements and add them to the map.
        String[] a = lines.get(1).split(" ");
        for (String s : a) {
            m.add(Integer.parseInt(s));
        }

        // Process the fourth line to toggle the presence of elements in the map.
        String[] b = lines.get(3).split(" ");
        for (String s : b) {
            int n = Integer.parseInt(s);
            if (m.contains(n)) {
                m.remove(Integer.valueOf(n));
            } else {
                m.add(n);
            }
        }

        // Extract the unique elements from the map and sort them.
        Collections.sort(m);

        // Print the sorted list of unique elements.
        for (int i : m) {
            System.out.println(i);
        }
    }
}

