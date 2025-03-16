import java.util.*;

public class Main {
    public static String run(String s, String t) {
        Map<Character, Integer> countS = new HashMap<>();
        Map<Character, Integer> countT = new HashMap<>();

        for (char c : s.toCharArray()) {
            countS.put(c, countS.getOrDefault(c, 0) + 1);
        }

        for (char c : t.toCharArray()) {
            countT.put(c, countT.getOrDefault(c, 0) + 1);
        }

        List<Integer> ss = new ArrayList<>(countS.values());
        List<Integer> tt = new ArrayList<>(countT.values());

        Collections.sort(ss);
        Collections.sort(tt);

        if (ss.equals(tt)) {
            return "Yes";
        } else {
            return "No";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        System.out.println(run(s, t));
    }
}

// <END-OF-CODE>
