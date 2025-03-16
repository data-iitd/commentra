
import java.util.*;
import java.io.*;

public class s509329039{
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] s = new int[m];
        int[] c = new int[m];
        for (int i = 0; i < m; i++) {
            s[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        for (int i = 0; i < 1000; i++) {
            String st = Integer.toString(i);
            if (st.length()!= n) {
                continue;
            }
            boolean f = true;
            for (int j = 0; j < m; j++) {
                if (st.charAt(s[j] - 1) - '0'!= c[j]) {
                    f = false;
                    break;
                }
            }
            if (f) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(-1);
    }
}

