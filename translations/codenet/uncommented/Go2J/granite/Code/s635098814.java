

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class s635098814{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<Character, Integer> map = new HashMap<>();
        while (true) {
            String s = br.readLine();
            if (s.equals("")) {
                break;
            }
            for (char c : s.toCharArray()) {
                if (Character.isUpperCase(c)) {
                    map.put(Character.toLowerCase(c), map.getOrDefault(Character.toLowerCase(c), 0) + 1);
                } else if (Character.isLowerCase(c)) {
                    map.put(c, map.getOrDefault(c, 0) + 1);
                }
            }
        }
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " : " + entry.getValue());
        }
    }
}

