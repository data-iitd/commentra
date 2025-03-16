
import java.util.*;

class s582614433 {
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
        Arrays.sort(s);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (s[j].equals(p[k])) {
                    System.out.println(k + 1);
                    break;
                }
            }
        }
    }
}

