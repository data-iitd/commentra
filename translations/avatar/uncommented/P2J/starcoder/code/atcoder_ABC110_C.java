import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        System.out.println(run(s, t));
    }
    public static String run(String s, String t) {
        List<Integer> ss = new ArrayList<Integer>();
        List<Integer> tt = new ArrayList<Integer>();
        for (int i = 0; i < s.length(); i++) {
            ss.add(s.charAt(i) - 'a');
        }
        for (int i = 0; i < t.length(); i++) {
            tt.add(t.charAt(i) - 'a');
        }
        Collections.sort(ss);
        Collections.sort(tt);
        if (ss.equals(tt)) {
            return "Yes";
        } else {
            return "No";
        }
    }
}
