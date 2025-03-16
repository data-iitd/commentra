

import java.util.*;

public class atcoder_ABC124_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        Map<Character, Integer> even = new HashMap<>();
        Map<Character, Integer> odd = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (i % 2 == 0) {
                even.put(c, even.getOrDefault(c, 0) + 1);
            } else {
                odd.put(c, odd.getOrDefault(c, 0) + 1);
            }
        }
        int result = Math.min(s.length() - (even.getOrDefault('0', 0) + odd.getOrDefault('1', 0)), s.length() - (even.getOrDefault('1', 0) + odd.getOrDefault('0', 0)));
        System.out.println(result);
    }
}
