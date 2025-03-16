import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        Map<Character, Integer> even = new HashMap<>();
        Map<Character, Integer> odd = new HashMap<>();
        for (int i = 0; i < n / 2; i++) {
            char c = s.charAt(i);
            if (c == '0') {
                even.put(c, even.getOrDefault(c, 0) + 1);
            } else {
                odd.put(c, odd.getOrDefault(c, 0) + 1);
            }
        }
        for (int i = n / 2; i < n; i++) {
            char c = s.charAt(i);
            if (c == '0') {
                odd.put(c, odd.getOrDefault(c, 0) + 1);
            } else {
                even.put(c, even.getOrDefault(c, 0) + 1);
            }
        }
        int min = Math.min(n - (even.get('0') + odd.get('1')), n - (even.get('1') + odd.get('0')));
        System.out.println(min);
    }
}

