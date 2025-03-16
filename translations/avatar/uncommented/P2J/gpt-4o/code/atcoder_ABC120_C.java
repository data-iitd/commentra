import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        
        if (new HashSet<>(Arrays.asList(s.split(""))).size() == 1) {
            System.out.println(0);
            return;
        }
        
        Map<Character, Integer> countMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
        }
        
        int ans = Collections.min(countMap.values()) * 2;
        System.out.println(ans);
    }
}
