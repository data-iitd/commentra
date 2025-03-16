
import java.util.*;

public class s700281300{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for(int i=0;i<n;i++) {
            String s = sc.next();

            Set<String> st = new HashSet<>();
            st.add(s);

            for(int j=1;j<s.length();j++) {
                StringBuilder sb = new StringBuilder();
                for(int k=0;k<j;k++) {
                    sb.append(s.charAt(k));
                }
                String res = sb.toString();

                StringBuilder sb2 = new StringBuilder();
                for(int k=j;k<s.length();k++) {
                    sb2.append(s.charAt(k));
                }
                String res2 = sb2.toString();

                String t = res;
                StringBuilder sb3 = new StringBuilder(t);
                sb3.reverse();
                String t2 = sb3.toString();

                st.add(t+t2);
                st.add(t2+t);

                st.add(t+res2);
                st.add(res2+t);

                st.add(res+t2);
                st.add(t2+res);

                st.add(res+res2);
                st.add(res2+res);
            }

            System.out.println(st.size());
        }
    }
}

