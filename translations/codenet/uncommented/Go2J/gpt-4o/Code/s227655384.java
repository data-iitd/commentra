import java.io.*;
import java.util.*;

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
                if (line.isEmpty()) {
                    break;
                }
            }
            result.add(buffer.toString());
            buffer.setLength(0); // Reset the buffer
        }
        return result;
    }

    // Method to print a list of integers
    public static void printList(List<Integer> list) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < list.size(); i++) {
            if (i > 0) {
                sb.append(" ");
            }
            sb.append(list.get(i));
        }
        System.out.println(sb.toString());
    }

    public static void main(String[] args) throws IOException {
        Map<Integer, Boolean> m = new HashMap<>();
        List<String> lines = readLongLines(4);
        
        String[] a = lines.get(1).split(" ");
        for (String s : a) {
            int n = Integer.parseInt(s);
            m.put(n, true);
        }

        List<Integer> result = new ArrayList<>();
        String[] b = lines.get(3).split(" ");
        for (String s : b) {
            int n = Integer.parseInt(s);
            if (m.containsKey(n)) {
                m.remove(n);
            } else {
                m.put(n, true);
            }
        }
        
        for (Integer k : m.keySet()) {
            result.add(k);
        }
        
        Collections.sort(result);
        printList(result);
    }
}
// <END-OF-CODE>
