import java.util.*;

public class Main {
    public static String run(String s, String t) {
        List<Integer> ss = getCharCounts(s);
        List<Integer> tt = getCharCounts(t);
        Collections.sort(ss);
        Collections.sort(tt);
        return ss.equals(tt) ? "Yes" : "No";
    }

    private static List<Integer> getCharCounts(String str) {
        Map<Character, Integer> charCountMap = new HashMap<>();
        for (char c : str.toCharArray()) {
            charCountMap.put(c, charCountMap.getOrDefault(c, 0) + 1);
        }
        List<Integer> counts = new ArrayList<>(charCountMap.values());
        return counts;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        System.out.println(run(s, t));
    }
}
