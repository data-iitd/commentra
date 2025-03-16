import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static String run(String s, String t) {
        Map<Character, Integer> sMap = new HashMap<>();
        Map<Character, Integer> tMap = new HashMap<>();

        for (char c : s.toCharArray()) {
            sMap.put(c, sMap.getOrDefault(c, 0) + 1);
        }

        for (char c : t.toCharArray()) {
            tMap.put(c, tMap.getOrDefault(c, 0) + 1);
        }

        int[] sFreq = new int[sMap.size()];
        int[] tFreq = new int[tMap.size()];

        int index = 0;
        for (int freq : sMap.values()) {
            sFreq[index++] = freq;
        }

        index = 0;
        for (int freq : tMap.values()) {
            tFreq[index++] = freq;
        }

        Arrays.sort(sFreq);
        Arrays.sort(tFreq);

        return Arrays.equals(sFreq, tFreq) ? "Yes" : "No";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        System.out.println(run(s, t));
    }
}
