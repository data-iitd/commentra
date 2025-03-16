
import java.io.*;
import java.util.*;

public class s644382798{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int q = Integer.parseInt(input[1]);

        Queue<String> queue = new LinkedList<>();
        Map<String, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            String name = input[0];
            int t = Integer.parseInt(input[1]);
            queue.add(name);
            map.put(name, t);
        }

        int elaps = 0;
        while (!queue.isEmpty()) {
            String name = queue.poll();
            int time = map.get(name);
            int c = Math.min(q, time);
            elaps += c;
            map.put(name, time - c);
            if (map.get(name) > 0) {
                queue.add(name);
            } else {
                System.out.println(name + " " + elaps);
            }
        }
    }
}
