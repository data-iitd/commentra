// Import necessary packages
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

// Main class
public class Main {
    // Method to read long lines from standard input
    public static List<String> readLongLines(int times) throws IOException {
        List<String> result = new ArrayList<>(times);
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder buffer = new StringBuilder();

        for (int i = 0; i < times; i++) {
            String line;
            while ((line = reader.readLine()) != null) {
                buffer.append(line);
                if (line.length() < 1024) { // Assuming a line is not too long if it's less than 1024 characters
                    break;
                }
            }
            result.add(buffer.toString());
            buffer.setLength(0); // Reset the buffer for the next iteration
        }
        return result;
    }

    // Method to print a list of integers
    public static void printList(List<Integer> list) throws IOException {
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < list.size(); i++) {
            if (i == 0) {
                writer.write(String.valueOf(list.get(i)));
            } else {
                writer.write(" " + list.get(i));
            }
        }
        writer.newLine();
        writer.flush();
    }

    // Main method
    public static void main(String[] args) {
        try {
            // Initialize a set to store unique integers
            HashSet<Integer> uniqueIntegers = new HashSet<>();
            // Read long lines from the standard input
            List<String> lines = readLongLines(4);
            // Split the second line into an integer array
            String[] a = lines.get(1).split(" ");
            // Add each integer to the set
            for (String s : a) {
                uniqueIntegers.add(Integer.parseInt(s));
            }

            // Read integers from the fourth line and add them to the set if they are not already present
            String[] b = lines.get(3).split(" ");
            for (String s : b) {
                uniqueIntegers.add(Integer.parseInt(s));
            }

            // Extract the unique integers from the set and store them in a list
            List<Integer> result = new ArrayList<>(uniqueIntegers);
            // Sort the result list in ascending order
            Collections.sort(result);

            // Print the sorted result list
            printList(result);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

// <END-OF-CODE>
