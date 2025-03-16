import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        Map<Integer, Boolean> map = new HashMap<>();
        List<Integer> result = new ArrayList<>();

        // Read 4 lines from standard input
        for (int i = 0; i < 4; i++) {
            String line = reader.readLine();
            if (i == 1) {
                String[] parts = line.split(" ");
                for (String part : parts) {
                    int num = Integer.parseInt(part);
                    map.put(num, true);
                }
            } else if (i == 3) {
                String[] parts = line.split(" ");
                for (String part : parts) {
                    int num = Integer.parseInt(part);
                    if (map.containsKey(num)) {
                        map.remove(num);
                    } else {
                        map.put(num, true);
                    }
                }
            }
        }

        // Collect remaining integers from the map into the result list
        for (int key : map.keySet()) {
            result.add(key);
        }

        // Sort the result list in ascending order
        Collections.sort(result);

        // Print the sorted result
        for (int num : result) {
            writer.write(num + "\n");
        }

        // Close the writer
        writer.flush();
    }
}

