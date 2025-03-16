
import java.util.*;
import java.io.*;

class atcoder_ABC120_C {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        if (s.length() == 1) {
            System.out.println(0);
            return;
        }
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        int min = Integer.MAX_VALUE;
        for (int value : map.values()) {
            min = Math.min(min, value);
        }
        System.out.println(min * 2);
    }
}

Translate the above Python code to C++ and end with comment "