import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
public final class Anagrams {
    private Anagrams() {
    }
    public static boolean approach1(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        char[] c = s.toCharArray();
        char[] d = t.toCharArray();
        Arrays.sort(c);
        Arrays.sort(d);
        return Arrays.equals(c, d);
    }
    public static boolean approach2(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] charCount = new int[26];
        for (int i = 0; i < s.length(); i++) {
            charCount[s.charAt(i) - 'a']++;
            charCount[t.charAt(i) - 'a']--;
        }
        for (int count : charCount) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
    public static boolean approach3(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] charCount = new int[26];
        for (int i = 0; i < s.length(); i++) {
            charCount[s.charAt(i) - 'a']++;
            charCount[t.charAt(i) - 'a']--;
        }
        for (int count : charCount) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
    public static boolean approach4(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        HashMap<Character, Integer> charCountMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            charCountMap.put(c, charCountMap.getOrDefault(c, 0) + 1);
        }
        for (char c : t.toCharArray()) {
            if (!charCountMap.containsKey(c) || charCountMap.get(c) == 0) {
                return false;
            }
            charCountMap.put(c, charCountMap.get(c) - 1);
        }
        return charCountMap.values().stream().allMatch(count -> count == 0);
    }
    public static boolean approach5(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] freq = new int[26];
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'a']++;
            freq[t.charAt(i) - 'a']--;
        }
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        int approach = scanner.nextInt();
        boolean result;
        switch (approach) {
            case 1:
                result = approach1(s, t);
                break;
            case 2:
                result = approach2(s, t);
                break;
            case 3:
                result = approach3(s, t);
                break;
            case 4:
                result = approach4(s, t);
                break;
            case 5:
                result = approach5(s, t);
                break;
            default:
                System.out.println("Invalid approach number.");
                scanner.close();
                return;
        }
        System.out.println("Are the strings anagrams? " + result);
        scanner.close();
    }
}
