
import java.util.*;

public class codeforces_637_A{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.next();
        }
        Arrays.sort(s);
        int max = 0;
        int index = -1;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (s[i].equals(s[j])) {
                    count++;
                }
            }
            if (max < count) {
                max = count;
                index = i;
            }
        }
        System.out.println(s[index]);
    }
}

Translate the above Java code to C++ and end with comment "