import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, Integer> s = new HashMap<String, Integer>();
        String[] l = new String[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.next();
        }
        String f = "Yes";
        int i = -1;
        for (String v : l) {
            if (s.containsKey(v)) {
                s.put(v, s.get(v) + 1);
            } else {
                s.put(v, 1);
            }
            if (s.get(v) >= 2) {
                f = "No";
            }
            if (i!= -1 && l[i].charAt(l[i].length() - 1)!= v.charAt(0)) {
                f = "No";
            }
            i++;
        }
        System.out.println(f);
    }
}
