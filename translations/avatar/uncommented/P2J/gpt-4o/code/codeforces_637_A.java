import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        String[] s = input.readLine().trim().split(" ");
        
        // Count occurrences of each word
        Map<String, Integer> w = new HashMap<>();
        for (String word : s) {
            w.put(word, w.getOrDefault(word, 0) + 1);
        }
        
        // Reverse the array
        Collections.reverse(Arrays.asList(s));
        
        String a = "";
        int c = -1;
        
        for (String key : w.keySet()) {
            if (w.get(key) == Collections.max(w.values())) {
                int index = Arrays.asList(s).indexOf(key);
                if (index > c) {
                    a = key;
                    c = index;
                }
            }
        }
        
        System.out.println(a);
    }
}
// <END-OF-CODE>
