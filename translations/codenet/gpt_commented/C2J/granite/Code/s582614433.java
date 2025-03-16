
import java.util.*;

public class s582614433{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] s = new String[n];
        long[] p = new long[n];
        int[] i = new int[n];
        for (int j = 0; j < n; j++) {
            s[j] = sc.next();
            p[j] = sc.nextLong();
            i[j] = j;
        }
        Arrays.sort(i, (a, b) -> {
            if (s[a].equals(s[b])) {
                return Long.compare(p[b], p[a]);
            } else {
                return s[a].compareTo(s[b]);
            }
        });
        for (int j : i) {
            System.out.println(j + 1);
        }
    }
}

