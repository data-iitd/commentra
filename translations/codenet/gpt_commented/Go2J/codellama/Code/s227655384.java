
package main;

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
        Map<Integer, Integer> map = new HashMap<>();
        List<String> lines = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            lines.add(reader.readLine());
        }
        String[] a = lines.get(1).split(" ");
        for (String s : a) {
            int n = Integer.parseInt(s);
            map.put(n, 1);
        }
        String[] b = lines.get(3).split(" ");
        for (String s : b) {
            int n = Integer.parseInt(s);
            if (map.containsKey(n)) {
                map.remove(n);
            } else {
                map.put(n, 1);
            }
        }
        List<Integer> result = new ArrayList<>();
        for (int n : map.keySet()) {
            result.add(n);
        }
        result.sort((lhs, rhs) -> lhs - rhs);
        for (int n : result) {
            System.out.println(n);
        }
    }
}

