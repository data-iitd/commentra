import java.io.*;
import java.util.*;

public class Main {
    // ReadLongLines reads multiple lines of input from stdin.
    public static List<String> readLongLines(int times) throws IOException {
        List<String> result = new ArrayList<>(times);
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder buffer = new StringBuilder();
        
        for (int i = 0; i < times; i++) {
            String line;
            while ((line = reader.readLine()) != null) {
                buffer.append(line);
                if (line.isEmpty()) {
                    break;
                }
            }
            result.add(buffer.toString());
            buffer.setLength(0); // Reset the buffer
        }
        return result;
    }

    // PrintList prints a list of integers separated by spaces.
    public static void printList(List<Integer> list) {
        Console console = System.console();
        if (console == null) {
            System.out.println("No console available");
            return;
        }
        for (int i = 0; i < list.size(); i++) {
            if (i == 0) {
                console.printf("%d", list.get(i));
            } else {
                console.printf(" %d", list.get(i));
            }
        }
        console.printf("%n");
    }

    public static void main(String[] args) {
        try {
            // Create a set to store unique elements.
            Set<Integer> uniqueElements = new HashSet<>();
            List<String> lines = readLongLines(4);

            // Split the second line into individual elements and add them to the set.
            String[] a = lines.get(1).split(" ");
            for (String s : a) {
                int n = Integer.parseInt(s);
                uniqueElements.add(n);
            }

            // Process the fourth line to toggle the presence of elements in the set.
            String[] b = lines.get(3).split(" ");
            for (String s : b) {
                int n = Integer.parseInt(s);
                if (uniqueElements.contains(n)) {
                    uniqueElements.remove(n);
                } else {
                    uniqueElements.add(n);
                }
            }

            // Extract the unique elements from the set and sort them.
            List<Integer> result = new ArrayList<>(uniqueElements);
            Collections.sort(result);

            // Print the sorted list of unique elements.
            printList(result);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
// <END-OF-CODE>
