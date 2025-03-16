import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        String[] tokens = input.readLine().split(" ");
        
        Map<Integer, Integer> w = new HashMap<>();
        for (String token : tokens) {
            int num = Integer.parseInt(token);
            w.put(num, w.getOrDefault(num, 0) + 1);
        }
        
        long c = 0;
        for (int i : w.keySet()) {
            if (i == 0) {
                c += (long) w.get(i) * (w.get(i) - 1);
            } else {
                if (w.containsKey(-i)) {
                    c += (long) w.get(i) * w.get(-i);
                }
            }
        }
        
        System.out.println(c / 2);
    }
}
// <END-OF-CODE>
