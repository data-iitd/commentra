
import java.util.*;

public class s700281300{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            String s = sc.next();
            Set<String> st = new HashSet<>();
            st.add(s);

            for (int j = 1; j < s.length(); j++) {
                StringBuilder sb = new StringBuilder();
                for (int k = 0; k < j; k++) {
                    sb.append(s.charAt(k));
                }
                String res = sb.reverse().toString();

                StringBuilder sb2 = new StringBuilder();
                for (int k = j; k < s.length(); k++) {
                    sb2.append(s.charAt(k));
                }
                String res2 = sb2.reverse().toString();

                st.add(res + res2);
                st.add(res2 + res);

                st.add(res + s.substring(j));
                st.add(s.substring(j) + res);

                st.add(s.substring(0, j) + res2);
                st.add(res2 + s.substring(0, j));
            }

            System.out.println(st.size());
        }
    }
}
