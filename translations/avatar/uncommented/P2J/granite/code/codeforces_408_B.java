
import java.util.*;
import java.io.*;

class codeforces_408_B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        HashMap<Character, Integer> bought_count = new HashMap<>();
        for (char c : line.toCharArray()) {
            bought_count.put(c, bought_count.getOrDefault(c, 0) + 1);
        }
        line = br.readLine();
        HashMap<Character, Integer> made_cout = new HashMap<>();
        for (char c : line.toCharArray()) {
            made_cout.put(c, made_cout.getOrDefault(c, 0) + 1);
        }
        int res = 0;
        for (char color : made_cout.keySet()) {
            if (!bought_count.containsKey(color)) {
                System.out.println(-1);
                return;
            }
            res += Math.min(bought_count.get(color), made_cout.get(color));
        }
        System.out.println(res);
    }
}

Translate the above Python code to C++ and end with comment "