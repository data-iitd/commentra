
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String[] line = reader.readLine().split(" ");
            for (String s : line) {
                int num = Integer.parseInt(s);
                if (map.containsKey(num)) {
                    map.put(num, map.get(num) + 1);
                } else {
                    map.put(num, 1);
                }
            }
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] line = reader.readLine().split(" ");
            for (String s : line) {
                int num = Integer.parseInt(s);
                if (map.containsKey(num)) {
                    if (map.get(num) == 1) {
                        map.remove(num);
                    } else {
                        map.put(num, map.get(num) - 1);
                    }
                } else {
                    map.put(num, 1);
                }
            }
        }
        for (int i : map.keySet()) {
            list.add(i);
        }
        list.sort((a, b) -> a - b);
        for (int i : list) {
            System.out.println(i);
        }
    }
}

