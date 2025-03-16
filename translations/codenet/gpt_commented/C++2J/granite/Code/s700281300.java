
import java.util.*;

public class s700281300{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            Set<String> set = new HashSet<>();
            set.add(s);
            for (int j = 1; j < s.length(); j++) {
                StringBuilder sb = new StringBuilder();
                for (int k = 0; k < j; k++) {
                    sb.append(s.charAt(k));
                }
                String res = sb.toString();
                StringBuilder sb2 = new StringBuilder();
                for (int k = j; k < s.length(); k++) {
                    sb2.append(s.charAt(k));
                }
                String res2 = sb2.toString();
                String t = res;
                String t2 = res2;
                StringBuilder sb3 = new StringBuilder();
                for (int k = t.length() - 1; k >= 0; k--) {
                    sb3.append(t.charAt(k));
                }
                String res3 = sb3.toString();
                StringBuilder sb4 = new StringBuilder();
                for (int k = t2.length() - 1; k >= 0; k--) {
                    sb4.append(t2.charAt(k));
                }
                String res4 = sb4.toString();
                set.add(t + t2);
                set.add(t2 + t);
                set.add(t + res2);
                set.add(res2 + t);
                set.add(res + t2);
                set.add(t2 + res);
                set.add(res + res2);
                set.add(res2 + res);
            }
            System.out.println(set.size());
        }
    }
}
