
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        String t = in.next();
        in.close();
        System.out.println(run(s, t));
    }

    public static String run(String s, String t) {
        // Count the frequency of each character in string s and sort the frequencies
        int[] ss = sortFrequency(s);
        
        // Count the frequency of each character in string t and sort the frequencies
        int[] tt = sortFrequency(t);
        
        // Compare the sorted frequency lists of both strings
        if (Arrays.equals(ss, tt)) {
            return "Yes";  // Return 'Yes' if the frequency distributions are the same
        } else {
            return "No";   // Return 'No' if the frequency distributions are different
        }
    }

    public static int[] sortFrequency(String s) {
        // Count the frequency of each character in string s
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            } else {
                map.put(c, 1);
            }
        }
        
        // Sort the frequencies
        int[] ss = new int[map.size()];
        int i = 0;
        for (Integer value : map.values()) {
            ss[i++] = value;
        }
        Arrays.sort(ss);
        return ss;
    }
}

