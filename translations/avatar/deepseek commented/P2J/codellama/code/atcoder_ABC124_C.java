
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        Map<Character, Integer> even = new HashMap<>();
        Map<Character, Integer> odd = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                even.put(s.charAt(i), even.getOrDefault(s.charAt(i), 0) + 1);
            } else {
                odd.put(s.charAt(i), odd.getOrDefault(s.charAt(i), 0) + 1);
            }
        }

        int min = Math.min(s.length() - (even.get('0') + odd.get('1')), s.length() - (even.get('1') + odd.get('0')));
        System.out.println(min);
    }
}

