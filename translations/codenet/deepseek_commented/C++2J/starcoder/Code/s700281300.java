import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for(int i=0;i<n;i++) {
            String s = in.next();
            Set<String> st = new HashSet<String>();
            st.add(s);
            for(int j=1;j<s.length();j++) {
                String res = "";
                for(int k=0;k<j;k++) {
                    res += s.charAt(k);
                }
                res = new StringBuilder(res).reverse().toString();
                String res2 = "";
                for(int k=j;k<s.length();k++) {
                    res2 += s.charAt(k);
                }
                res2 = new StringBuilder(res2).reverse().toString();
                String t = res;
                String t2 = res2;
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

