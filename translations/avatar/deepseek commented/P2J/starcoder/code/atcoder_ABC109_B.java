import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, Integer> s = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String v = sc.next();
            s.put(v, s.getOrDefault(v, 0) + 1);
        }
        String f = "Yes";
        for (String v : s.keySet()) {
            if (s.get(v) >= 2) {
                f = "No";
            }
            if (i!= -1 && l.get(i).charAt(l.get(i).length() - 1)!= v.charAt(0)) {
                f = "No";
            }
        }
        System.out.println(f);
    }
}

